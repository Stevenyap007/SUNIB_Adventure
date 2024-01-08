import os
import cv2
import numpy as np
import matplotlib.pyplot as plt

image_scene = cv2.imread('kitkat_scene.jpg')
image_targetList = []

image_pathList = []
for path in os.listdir('./targetList'):
    image_pathList.append('./targetList/' + path)

for i in range (len(image_pathList)):
    image = cv2.imread(image_pathList[i])
    image = cv2.blur(image, (2,2))
    image_targetList.append(image)

# ORB

# Keypoint and Descriptor
ORB = cv2.ORB_create()
ORB_keypoint_scene, ORB_descriptor_scene = ORB.detectAndCompute(image_scene,None)

ORB_keypoint_Target = []
ORB_descriptor_Target = []

for image in image_targetList:
    keypoint, descriptor = ORB.detectAndCompute(image, None)
    ORB_keypoint_Target.append(keypoint)
    ORB_descriptor_Target.append(descriptor)

#Matcher
bfmatcher = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck = True)
ORB_match_result = []
for descriptor in ORB_descriptor_Target:
    match_result = bfmatcher.match(descriptor,ORB_descriptor_scene)
    match_result = sorted(match_result, key = lambda x : x.distance)
    ORB_match_result.append(match_result)

ORB_result = max(ORB_match_result,key = len)
ORB_Image_Index = ORB_match_result.index(ORB_result)

#draw matches
ORB_res = cv2.drawMatches(
    image_targetList[ORB_Image_Index],ORB_keypoint_Target[ORB_Image_Index],
    image_scene,ORB_keypoint_scene,
    ORB_result[:30],None,
    matchColor = [255,0,0],
    singlePointColor = [0,0,255],
    # flags = 2
)
ORB_res = cv2.cvtColor(ORB_res, cv2.COLOR_BGR2RGB)

#SIFT
SIFT = cv2.SIFT_create()

# Keypoint dan descriptor
sift_keypoint_scene, sift_descriptor_Scene = SIFT.detectAndCompute(image_scene,None)
sift_descriptor_scene = np.float32(sift_descriptor_Scene)
sift_keypoint_target = []
sift_descriptor_target = []

for image in image_targetList:
    keypoint, descriptor = SIFT.detectAndCompute(image,None)
    descriptor = np.float32(descriptor)
    sift_keypoint_target.append(keypoint)
    sift_descriptor_target.append(descriptor)

# Matcher

flann = cv2.FlannBasedMatcher(dict(algorithm=1),dict(checks=50))
sift_match_result = []
for descriptor in sift_descriptor_target:
    match_result = flann.knnMatch(descriptor, sift_descriptor_scene, 2)
    sift_match_result.append(match_result)

sift_result = max(sift_match_result, key=len)
sift_image_index = sift_match_result.index(sift_result)
sift_matches_mask = [[0,0] for i in range (len(sift_result))]
def createMasking(mask, match):
    for i, (fm,sm) in enumerate(match):
        if fm.distance < 0.7 * sm.distance:
            mask[i] = [1,0]
    return mask
sift_matches_mask = createMasking(sift_matches_mask, sift_result)

sift_res = cv2.drawMatchesKnn(
    image_targetList[sift_image_index], sift_keypoint_target[sift_image_index], 
    image_scene, sift_keypoint_scene, 
    sift_result, None, 
    matchColor=[255,0,0],
    singlePointColor=[0,255,0],
    matchesMask = sift_matches_mask
)

sift_res = cv2.cvtColor(sift_res, cv2.COLOR_BGR2RGB)

#AKAZE
AKAZE = cv2.AKAZE_create()

# Keypoint dan descriptor
akaze_keypoint_scene, akaze_descriptor_Scene = AKAZE.detectAndCompute(image_scene,None)
akaze_descriptor_scene = np.float32(akaze_descriptor_Scene)
akaze_keypoint_target = []
akaze_descriptor_target = []

for image in image_targetList:
    keypoint, descriptor = AKAZE.detectAndCompute(image,None)
    descriptor = np.float32(descriptor)
    akaze_keypoint_target.append(keypoint)
    akaze_descriptor_target.append(descriptor)

# Matcher

flann = cv2.FlannBasedMatcher(dict(algorithm=1),dict(checks=1))
akaze_match_result = []
for descriptor in akaze_descriptor_target:
    akaze_match_result.append(flann.knnMatch(descriptor, akaze_descriptor_scene, 2))

akaze_result = max(akaze_match_result, key=len)
akaze_image_index = akaze_match_result.index(akaze_result)
akaze_matches_mask = [[0,0] for i in range (len(akaze_result))]
def createMasking(mask, match):
    for i, (m,n) in enumerate(match):
        if m.distance < 0.7 * n.distance:
            mask[i] = [1,0]
    return mask
akaze_matches_mask = createMasking(akaze_matches_mask, akaze_result)

akaze_res = cv2.drawMatchesKnn(
    image_targetList[akaze_image_index], akaze_keypoint_target[akaze_image_index], 
    image_scene, akaze_keypoint_scene, 
    akaze_result, None, 
    matchColor=[255,0,0],
    singlePointColor=[0,255,0],
    matchesMask = akaze_matches_mask
)

akaze_res = cv2.cvtColor(akaze_res, cv2.COLOR_BGR2RGB)

# show image
plt.figure(figsize=(12,12))
plt.subplot(2,2,1)
plt.imshow(sift_res)
plt.title('SIFT')
plt.show()



