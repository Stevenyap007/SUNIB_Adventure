import numpy as np
import cv2

image = cv2.imread('image.png')
# print(image, image.ndim, image.shape , image.size)
image_b = image.copy()
image_b[:,:,(1,2)] = 0

image_r = image.copy()
image_r[:,:,(0,1)] = 0

image_g = image.copy()
image_g[:,:,(0,2)] = 0

image_br = np.vstack((image_b, image_r))

cv2.imshow('image',image_g)
cv2.waitKey(0)
cv2.destroyAllWindows()

# cv2.imwrite('image_br.png',image_br)