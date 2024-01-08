import cv2
import matplotlib.pyplot as plt
import numpy as np



# print('Hello world')

# image read
# Blue Green Red
# image_1 = cv2.imread('image_1.jpg')

# image show
# cv2.imshow('image_1', image_1)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

# BGR -> RGB
# Red Green Blue

# image.shape
# print(image_1.shape)
# image_1 = cv2.resize(image_1, (500 , 200), cv2.INTER_AREA)

# image_RGB = cv2.cvtColor(image_1, cv2.COLOR_BGR2RGB)
# plt.imshow(image_1)
# plt.show()

# image_1 = cv2.imread('image_1.jpg')
# image_2 = cv2.imread('image_2.png')

# image_1 = cv2.cvtColor(image_1, cv2.COLOR_BGR2GRAY)
# image_2 = cv2.cvtColor(image_2, cv2.COLOR_BGR2GRAY)

# sub plot 
#plt.subplot(sizeX, SizeY, posisi)
# 2 x 1

# plt.subplot(1,2,1) # buat plot ukuran 1x2, di posisi 1
# plt.imshow(image_1, cmap='gray')
# plt.xticks([]) # ilangin angka di sumbu x
# plt.yticks([]) # ilangin angka di sumbu y
# plt.title('Waifu') #kasih title

# plt.subplot(1,2,2) # buat plot ukuran 1x2, di posisi 2
# plt.imshow(image_2, cmap='gray')
# plt.xticks([])
# plt.yticks([])
# plt.title('Smurf Cat')


# Histogram grafik intensitas warna
# grayscale 0 - 255

image_2 = cv2.imread('image_2.png')
image_2 = cv2.cvtColor(image_2, cv2.COLOR_BGR2GRAY)

print(image_2.shape)

width = image_2.shape[0] # dapetin lebar foto
height = image_2.shape[1] # dapetin tinggi foto

# intensity_counter = np.zeros(shape=256, dtype=int)

# for i in range(width): # looping sebanyak lebar
#     for j in range(height): # looping sebanyak tinggi
#         intensity = image_2[i][j] # akses intensitas pixel ke i dan j
#         intensity_counter[intensity] += 1 # tambah 1

# plt.plot(intensity_counter)
# plt.show()

image_equalized = cv2.equalizeHist(image_2)

# clahe
clahe = cv2.createCLAHE()
image_clahe = clahe.apply(image_2)
image_clahe_equalized = clahe.apply(image_equalized)

# nampilin plot histogram
plt.subplot(1,4,1)
plt.hist(image_2.flat, bins = 256, range=(0,255))

plt.subplot(1,4,2)
plt.hist(image_equalized.flat, bins = 256, range=(0,255))

plt.subplot(1,4,3)
plt.hist(image_clahe.flat, bins = 256, range=(0,255))

plt.subplot(1,4,4)
plt.hist(image_clahe_equalized.flat, bins = 256, range=(0,255))
plt.show()

# nampilin gambar
plt.subplot(1,4,1)
plt.imshow(image_2, cmap='gray')
plt.xticks([])
plt.yticks([])

plt.subplot(1,4,2)
plt.imshow(image_equalized, cmap='gray')
plt.xticks([])
plt.yticks([])

plt.subplot(1,4,3)
plt.imshow(image_clahe, cmap='gray')
plt.xticks([])
plt.yticks([])

plt.subplot(1,4,4)
plt.imshow(image_clahe, cmap='gray')
plt.xticks([])
plt.yticks([])


plt.show()

