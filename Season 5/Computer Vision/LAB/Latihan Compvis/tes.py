# AKAZE
AKAZE = cv2.AKAZE_create()

# keypoint and descriptor
akaze_keypoint_scene, akaze_descriptor_scene = AKAZE.detectAndCompute(image_scene,None)
akaze_descriptor_scene = np.float32(akaze_descriptor_scene)

akaze_keypoint_target = []
akaze_descriptor_target = []
for image in image_targetList:
    keypoint, descriptor = AKAZE.detectAndCompute(image,None)
    descriptor = np.float32(descriptor)
    akaze_keypoint_target.append(keypoint)
    akaze_descriptor_target.append(descriptor)

#matcher

flann = cv2.FlannBasedMatcher(dict(algorithm=1),dict(checks=1))
akaze_match_result=[]
for descriptor in akaze_descriptor_target:
    akaze_match_result.append(flann.knnMatch(descriptor, akaze_descriptor_scene, 2))

akaze_result = max(akaze_match_result, key = len)
akaze_image_index = akaze_match_result.index(akaze_result)
akaze_matches_mask = [[0,0] for i in range (len(akaze_result))]
def createMasking(mask,match):
    for i ,(m,n) in enumerate (match):
        if m.distance < 0.7*n.distance:
            mask[i] = [1,0]
        return mask
akaze_matches_mask= createMasking(akaze_matches_mask,akaze_result)

akaze_res = cv2.drawMatchesKnn(
    image_targetList[akaze_image_index],akaze_keypoint_target[akaze_image_index],
    image_scene,akaze_keypoint_scene,
    akaze_result, None,
    matchColor = [255,0,0], 
    singlePointColor = [0,255,0],
    matchesMask = akaze_matches_mask
)

akaze_res = cv2.cvtColor(akaze_res,cv2.COLOR_BGR2RGB)