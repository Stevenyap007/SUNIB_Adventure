import os
import cv2
import numpy as np
from scipy.cluster.vq import * #vector quantimevasion
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
import matplotlib.pyplot as plt

train_dir_path = './images/train'

train_image_paths = []
train_image_classes = []

class2id = {'pancake': 0, 'pizza' : 1, 'popcorn' :2}
id2class = ['pancake','pizza','popcorn']

for image_class in os.listdir(train_dir_path):
    image_class_path = f'{train_dir_path}/{image_class}' #biar '' tidak kebaca sebagai string

    for path in os.listdir(image_class_path):
        image_path = f'{image_class_path}/{path}'
        # print(image_path)
        train_image_paths.append(image_path)
        train_image_classes.append(class2id[image_class])

# print(train_image_paths)
# print(train_image_classes)

# Image Feature Extraction
sift = cv2.SIFT_create()

train_image_descriptors = []

for image_path in train_image_paths:
    _, descriptor = sift.detectAndCompute(cv2.imread(image_path),None)
    train_image_descriptors.append(descriptor)

# print(train_image_descriptors)
train_stacked_descriptors = train_image_descriptors[0]

for descriptor in train_image_descriptors[1:]:
    train_stacked_descriptors = np.vstack((train_stacked_descriptors,descriptor))

train_stacked_descriptors = np.float32(train_stacked_descriptors)

# print(train_stacked_descriptors)

# Clustering and create Histogram
centroids, _ = kmeans(train_stacked_descriptors, 100, 2)

train_image_features_size = (len(train_image_paths),len(centroids))
train_image_features = np.zeros(train_image_features_size, np.float32)

for i in range(len(train_image_paths)):
    words, _ = vq(train_image_descriptors[i],centroids)
    for w in words:
        train_image_features[i][w] += 1

# print(train_image_features)
scaler = StandardScaler()
train_image_features = scaler.fit_transform(train_image_features)

print(train_image_features)

#build SVM Model
model = SVC()

# X_train = train_image_Features
# y_train = train_image_Clases
model.fit(train_image_features,train_image_classes)

# Read test data
test_dir_path = './images/test'
test_image_paths = []

for path in os.listdir(test_dir_path):
    image_path = f'{test_dir_path}/{path}'
    test_image_paths.append(image_path)

# Extract test data features
test_image_descriptors = []

for image_path in test_image_paths:
    _, descriptor = sift.detectAndCompute(cv2.imread(image_path),None)
    test_image_descriptors.append(descriptor)

test_stacked_descriptors = test_image_descriptors[0]
for descriptor in test_image_descriptors[1:]:
    test_stacked_descriptors = np.vstack((test_stacked_descriptors,descriptor))

test_stacked_descriptors = np.float32(test_stacked_descriptors)
centroids,_ = kmeans(test_stacked_descriptors,100,2)

test_image_features_size = (len(test_image_paths), len(centroids))
test_image_features = np.zeros(test_image_features_size,np.float32)

for i in range (len(test_image_paths)):
    words,_ = vq(test_image_descriptors[i], centroids)
    for w in words:
        test_image_features[i][w] += 1

test_image_features = scaler.fit_transform(test_image_features)

# X_test = test_image_features
# Y_pred = model.predict(X_test)

predictions = model.predict(test_image_features)

plt.figure(figsize=(12,6))

for index, (pred, image_path) in enumerate(zip(predictions,test_image_paths)):
    plt.subplot(2,5, index+1)
    image = cv2.imread(image_path)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    plt.imshow(image)
    plt.xticks([])
    plt.yticks([])
    plt.title(id2class[pred])


plt.tight_layout()
plt.show()