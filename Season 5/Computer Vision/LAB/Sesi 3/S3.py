import numpy as np
import matplotlib.pyplot as plt
import cv2

image = cv2.imread('lena.jpg')
image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

def show_result(res_stack, nrows=None, ncols=None):
    plt.figure(figsize=(12,12))

    for i, (label, image) in enumerate(res_stack):
        plt.subplot(nrows,ncols, i + 1)
        plt.imshow(image, cmap='gray')
        plt.title(label)
    

    plt.show()



#average Grayscaling
image_gray_avg = np.dot(image_rgb, [1/3, 1/3, 1/3])
# plt.imshow(image_gray_avg, cmap = 'gray')
# plt.show()

# weighted Average Grayscaling
image_gray_wag = np.dot(image_rgb, [0.2,0.5,0.3])

# Lightness Grayscaling
image_r = image[:,:, 2]
image_b = image[:,:, 0]
image_g = image[:,:, 1]
# b, g , r = cv2.split(image)

# Get max and min value of each channel
image_max = np.max((np.max(image_r), np.max(image_b), np.max(image_g)))
image_min = np.min((np.min(image_r), np.min(image_b), np.min(image_g)))

weight_value = (image_max + image_min) / 2
image_gray_lig = np.dot(image,[weight_value, weight_value, weight_value])


# OpenCV Grayscaling
image_gray_ocv = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
# plt.imshow(image_gray_ocv, cmap ='gray')
# plt.show()

labels = ['avg', 'ocv', 'wag', 'lig']
images = [image_gray_avg, image_gray_ocv, image_gray_wag,image_gray_lig]

# zip(labels, image) -> [('avg', imag_gray_avg),...]
# show_result(zip(labels,images),2,3)


height, width = image.shape[:2] # (512, 512,3) -> (512,512)

image_gray = image_gray_ocv.copy()
# manual Threshold

for i in range(height):
    for j in range(width):
        if(image_gray[i,j] < 100):
            image_gray[i,j] = 0
        else:
            image_gray[i,j] = 255


_, bin_thresh = cv2.threshold(image_gray_ocv.copy(), 100,255, cv2.THRESH_BINARY)
_, bininv_thresh = cv2.threshold(image_gray_ocv.copy(), 150, 255, cv2.THRESH_BINARY_INV)
_, trunc_thresh = cv2.threshold(image_gray_ocv.copy(), 50,255, cv2.THRESH_TRUNC)
_, tozero_thresh = cv2.threshold(image_gray_ocv.copy(), 100,255, cv2.THRESH_TOZERO)
_, tozeroinv_thresh = cv2.threshold(image_gray_ocv.copy(), 100,255, cv2.THRESH_TOZERO_INV)

labels = ['manual','bin','bininv','trunc','tozero','tozeroinv']
images = [image_gray,bin_thresh,bininv_thresh,trunc_thresh,tozero_thresh,tozeroinv_thresh]

# show_result(zip(labels,images),2,3)

# Manual mean Filter
def manual_mean_filter(source, ksize):
    for i in range(height - ksize - 1):
        for j in range(width - ksize - 1):
            matrix = np.array(source[i:i+ksize, j:j+ksize]).flatten()
            mean = np.mean(matrix)
            source[(i + ksize) // 2, (j + ksize) // 2] = mean
    return source


b, g, r = cv2.split(image)
mean_b = manual_mean_filter(b,15)
mean_g = manual_mean_filter(g,15)
mean_r = manual_mean_filter(r,15)
merged_mean = cv2.merge((mean_b, mean_g, mean_r))
merged_mean = cv2.cvtColor(merged_mean, cv2.COLOR_BGR2RGB)

labels = ['manual mean']
images = [merged_mean]

show_result(zip(labels,images),1,1)

