import matplotlib.pyplot as plt
import cv2
import numpy as np

# image = cv2.imread('image2.png')
# cv2.imshow('image',image)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

def showResult(nRow=None, nCol=None, res_stack = None ):
    plt.figure(figsize=(12,12))
    for i, (label,image) in enumerate(res_stack):
        plt.subplot(nRow,nCol,i+1)
        plt.imshow(image, cmap='gray')
        plt.title(label)
        plt.axis('off')
    plt.show()



# kalkulasi tinggi dan lebar foto
# height, width = image.shape[:2]
# def manual_median_filter(source, ksize):
#     np_source = np.array(source)
#     for i in range(height - ksize - 1):
#         for j in range(width - ksize - 1):
#             matrix = np.array(np_source[i : (i+ksize),j:(j+ksize)]).flatten()
#             median = np.median(matrix)
#             np_source[i+ksize // 2, j+ksize // 2] = median
#     return np_source

# b, g, r = cv2.split(image)
# median_b = manual_median_filter(b, 15)# 15 itu kernel size jadi kalo makin tinggi makin blur
# median_g = manual_median_filter(g, 15)
# median_r = manual_median_filter(r, 15)

# median_image = cv2.merge((median_b,median_g,median_r))

#blur
# blur_image = cv2.blur(image, (15,15))
#median
# median_image = cv2.medianBlur(image,15)
#gaussian
# gaussian_image = cv2.GaussianBlur(image,(15,15),2.0)
#bilateral
# bilateral_image = cv2.bilateralFilter(image, 1, 150, 150)


# images = [image,blur_image,median_image,gaussian_image,bilateral_image]
# labels = ['jeruk','jeruk blur','jeruk_median','gaussian_median','bilateral_median']

# showResult(2,3,zip(labels,images))

image = cv2.imread('image_3.png')
image = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
# image = cv2.equalizeHist(image)
# clahe = cv2.createCLAHE()
# image = clahe.apply(image)

# 8 bit unsigned integer
# 16 bit signed integer
# 32 bit float
# 64 bit float

laplace_8U = cv2.Laplacian(image,cv2.CV_8U)
laplace_16S = cv2.Laplacian(image,cv2.CV_16S)
laplace_32F = cv2.Laplacian(image,cv2.CV_32F)
laplace_64F = cv2.Laplacian(image,cv2.CV_64F)



images = [laplace_8U,laplace_16S,laplace_32F,laplace_64F]
labels = ['laplace_8U','laplace_16S','laplace_32F','laplace_64F']

showResult(2,2,zip(labels,images))

#canny
canny_50100 = cv2.Canny(image ,50,100)
canny_50150 = cv2.Canny(image ,50,150)
canny_75150 = cv2.Canny(image ,75,150)
canny_75225 = cv2.Canny(image ,75,225)

images = [canny_50100,canny_50150,canny_75150,canny_75225]
labels = ['canny_50100','canny_50150','canny_75150','canny_75225']

showResult(2,2,zip(labels,images))

# sobel
ksize = 3
sobel_x = cv2.Sobel(image, cv2.CV_32F, 1, 0, ksize)
sobel_y = cv2.Sobel(image, cv2.CV_32F, 0, 1, ksize)
sobel_merged = np.sqrt(np.square(sobel_x) + np.square(sobel_y))
sobel_merged2 = np.abs(sobel_x) + np.abs(sobel_y)

images = [sobel_x,sobel_y,sobel_merged,sobel_merged2]
labels = ['sobel_x','sobel_y','sobel_merged','sobel_merged2']
showResult(2,2,zip(labels,images))
