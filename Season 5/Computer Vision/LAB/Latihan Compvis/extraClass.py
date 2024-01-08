import cv2
import numpy as np
import matplotlib.pyplot as plt
import os

image_Scene = cv2.imread("./kitkat_scene.jpg")
image_targetList = []

image_PathList = []
for path in os.listdir('./targetList'):
    image_PathList.append('./targetList/' + path)
    # print(path)

for i in range(len(image_PathList)):
    # print(image_PathList[i])
    image = cv2.imread(image_PathList[i])
    image = cv2.blur(image, (2,2))
    image_targetList.append(image)

SIFT = cv2.SIFT_create()
ORB = cv2.ORB_create()
AKAZE = cv2.AKAZE_create()

#SIFT
sift_keypoint_Target = []
sift_Descriptor_Target = []
sift_keypoint_Scene, sift_Descriptor_Scene = SIFT.detectAndCompute(image_Scene,None)
sift_Descriptor_Scene = np.float32(sift_Descriptor_Scene)

for image in image_targetList:
    keypoint, descriptor = SIFT.detectAndCompute(image,None)
    descriptor = np.float32(descriptor)
    sift_keypoint_Target.append(keypoint)
    sift_Descriptor_Target.append(descriptor)

#ORB
orb_keypoint_Target = []
orb_Descriptor_Target = []
orb_keypoint_Scene, orb_Descriptor_Scene = ORB.detectAndCompute(image_Scene,None)

for image in image_targetList:
    keypoint, descriptor = ORB.detectAndCompute(image,None)
    orb_keypoint_Target.append(keypoint)
    orb_Descriptor_Target.append(descriptor)

#AKAZE
akaze_keypoint_Target = []
akaze_Descriptor_Target = []
akaze_keypoint_Scene, akaze_Descriptor_Scene = AKAZE.detectAndCompute(image_Scene,None)
akaze_Descriptor_Scene = np.float32(akaze_Descriptor_Scene)

for image in image_targetList:
    keypoint, descriptor = AKAZE.detectAndCompute(image,None)
    descriptor = np.float32(descriptor)
    akaze_keypoint_Target.append(keypoint)
    akaze_Descriptor_Target.append(descriptor)

#Matcher
# SIFT dan AKAZE = FLANN
# ORB = BFMATCHER

flann = cv2.FlannBasedMatcher(dict(algorithm=1),dict(checks=50))
bfmatcher = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck = True)

def createMasking(mask, match):
    for i, (fm,sm) in enumerate(match):
        if fm.distance < 0.7 * sm.distance:
            mask[i] = [1,0]
    return mask

#SIFT
sift_match_Result = []
for descriptor in sift_Descriptor_Target:
    sift_match_Result.append(flann.knnMatch(descriptor, sift_Descriptor_Scene, 2))

sift_Result = max(sift_match_Result, key=len)
sift_Image_Index = sift_match_Result.index(sift_Result)
sift_matches_mask = [[0,0] for i in range (len(sift_Result))]
sift_matches_mask = createMasking(sift_matches_mask, sift_Result)

sift_res = cv2.drawMatchesKnn(
    image_targetList[sift_Image_Index], 
    sift_keypoint_Target[sift_Image_Index], 
    image_Scene, 
    sift_keypoint_Scene, 
    sift_Result, None, 
    matchColor=[355,0,0],
    singlePointColor=[0,255,0],
    matchesMask = sift_matches_mask
)

sift_res = cv2.cvtColor(sift_res, cv2.COLOR_BGR2RGB)

#ORB
orb_match_Result = []
for descriptor in orb_Descriptor_Target:
    match_Result = bfmatcher.match(descriptor, orb_Descriptor_Scene)
    match_Result = sorted(match_Result, key = lambda x : x.distance)
    orb_match_Result.append(match_Result)

orb_Result = max(orb_match_Result, key=len)
orb_Image_index = orb_match_Result.index(orb_Result)

orb_res = cv2.drawMatches(
    image_targetList[orb_Image_index],
    orb_keypoint_Target[orb_Image_index],
    image_Scene, orb_keypoint_Scene,
    orb_Result[:30], None,
    matchColor=[255,0,0],
    singlePointColor=[0,255,0],
    flags = 2
)

orb_res = cv2.cvtColor(orb_res, cv2.COLOR_BGR2RGB)

#AKAZE
akaze_match_Result = []
for descriptor in akaze_Descriptor_Target:
    akaze_match_Result.append(flann.knnMatch(descriptor, akaze_Descriptor_Scene, 2))

akaze_Result = max(akaze_match_Result, key=len)
akaze_Image_Index = akaze_match_Result.index(akaze_Result)
akaze_matches_mask = [[0,0] for i in range (len(akaze_Result))]
akaze_matches_mask = createMasking(akaze_matches_mask, akaze_Result)

akaze_res = cv2.drawMatchesKnn(
    image_targetList[akaze_Image_Index], 
    akaze_keypoint_Target[akaze_Image_Index], 
    image_Scene, 
    akaze_keypoint_Scene, 
    akaze_Result, None, 
    matchColor=[255,0,0],
    singlePointColor=[0,255,0],
    matchesMask = akaze_matches_mask
)

akaze_res = cv2.cvtColor(akaze_res, cv2.COLOR_BGR2RGB)

plt.figure(figsize=(12,12))
plt.subplot(2,2,1)
plt.imshow(sift_res)
plt.title('SIFT')
plt.show()