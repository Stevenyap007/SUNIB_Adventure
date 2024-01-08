import cv2
import matplotlib.pyplot as plt
import numpy as np

def show_image(nrow, ncol, res):
    for i, (label,image) in enumerate(res):
        plt.subplot(nrow,ncol, i+1)
        plt.imshow(image)
        plt.title(label)
        plt.axis('off')
    plt.show()

marjan = cv2.imread('marjan_1.png')
marjan = cv2.cvtColor(marjan, cv2.COLOR_BGR2RGB)
marjan_banyak = cv2.imread('marjan_banyak.png')
marjan_banyak = cv2.cvtColor(marjan_banyak, cv2.COLOR_BGR2RGB)

# ------ ORB -------- #
# paling cepat


ORB = cv2.ORB_create()

# k = keypoints, d = descriptors
ORB_marjan_k, ORB_marjan_d = ORB.detectAndCompute(marjan,None)
ORB_marjan_banyak_k, ORB_marjan_banyak_d = ORB.detectAndCompute(marjan_banyak,None)

BF_MATCHER = cv2.BFMatcher_create()
ORB_match = BF_MATCHER.match(ORB_marjan_d,ORB_marjan_banyak_d)

ORB_match = sorted(ORB_match,key =  lambda x:x.distance)


ORB_result = cv2.drawMatches(
    marjan, ORB_marjan_k,
    marjan_banyak,ORB_marjan_banyak_k,
    ORB_match[:20],None,
    matchColor=[255,0,0], # RGB -> Merah doang
    singlePointColor=[0,0,255] # RGB -> Biru doang
)


# images = [ORB_result]
# labels = ['ORB_result']

# show_image(1,1,zip(labels,images))



# --------- SIFT ---------- #

SIFT = cv2.SIFT_create()

SIFT_marjan_k, SIFT_marjan_d = SIFT.detectAndCompute(marjan,None)
SIFT_marjan_banyak_k, SIFT_marjan_banyak_d = SIFT.detectAndCompute(marjan_banyak,None)

FLANN_matcher = cv2.FlannBasedMatcher(dict(algorithm=1), dict(checks=1))

SIFT_match = FLANN_matcher.knnMatch(SIFT_marjan_d,SIFT_marjan_banyak_d,2)

SIFT_mask = [[0,0] for i in range(len(SIFT_match))] # array 0,0 sebanyak tali talinya

for i, (m,n) in enumerate(SIFT_match): 
    if m.distance < 0.7 * n.distance: #cek apakah distance m  memenuhi ini klo bagus tampilin
        SIFT_mask[i] = [1,0]

#mask
SIFT_result = cv2.drawMatchesKnn(
    marjan, SIFT_marjan_k,
    marjan_banyak,SIFT_marjan_banyak_k,
    SIFT_match,None,
    matchColor=[255,0,0], # RGB -> Merah doang
    singlePointColor=[0,0,255], # RGB -> Biru doang
    matchesMask= SIFT_mask
)

# --------- AKAZE ---------- #

AKAZE = cv2.AKAZE_create()

AKAZE_marjan_k, AKAZE_marjan_d = AKAZE.detectAndCompute(marjan,None)
AKAZE_marjan_banyak_k, AKAZE_marjan_banyak_d = AKAZE.detectAndCompute(marjan_banyak,None)

FLANN_matcher = cv2.FlannBasedMatcher(dict(algorithm=1), dict(checks=1))

AKAZE_marjan_d = np.float32(AKAZE_marjan_d)
AKAZE_marjan_banyak_d = np.float32(AKAZE_marjan_banyak_d)

AKAZE_match = FLANN_matcher.knnMatch(AKAZE_marjan_d,AKAZE_marjan_banyak_d,2)

AKAZE_mask = [[0,0] for i in range(len(AKAZE_match))] # array 0,0 sebanyak tali talinya

for i, (m,n) in enumerate(AKAZE_match): 
    if m.distance < 0.7 * n.distance: #cek apakah distance m  memenuhi ini klo bagus tampilin
        AKAZE_mask[i] = [1,0]

#mask
AKAZE_result = cv2.drawMatchesKnn(
    marjan, AKAZE_marjan_k,
    marjan_banyak,AKAZE_marjan_banyak_k,
    AKAZE_match,None,
    matchColor=[255,0,0], # RGB -> Merah doang
    singlePointColor=[0,0,255], # RGB -> Biru doang
    matchesMask= AKAZE_mask
)





images = [ORB_result,SIFT_result,AKAZE_result]
labels = ['ORB_result','SIFT_result','AKAZE_result']

show_image(1,2,zip(labels,images))