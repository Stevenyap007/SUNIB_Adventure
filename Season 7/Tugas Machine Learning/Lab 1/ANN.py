import pandas as pd
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.model_selection import train_test_split, cross_val_score
from imblearn.over_sampling import SMOTE
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import classification_report, confusion_matrix, roc_auc_score, ConfusionMatrixDisplay
import matplotlib.pyplot as plt
import joblib
import numpy as np

file_path = 'heart_disease_uci.csv'
data = pd.read_csv(file_path)

text_to_number = {
    "four -eight": 48
}
print(data.info())
data['age'] = data['age'].replace(text_to_number)
data['age'] = pd.to_numeric(data['age'], errors='coerce')
# print(data.describe())
numerical_cols = ['age', 'trestbps', 'chol', 'thalch', 'oldpeak', 'ca']
categorical_cols = ['fbs', 'restecg', 'slope', 'thal', 'exang']

# print(data.describe())

# simpleimputer untuk ngisi nilai yg hilang
print(data.isna().sum())
num_imputer = SimpleImputer(strategy='mean')
data[numerical_cols] = num_imputer.fit_transform(data[numerical_cols])

cat_imputer = SimpleImputer(strategy='most_frequent')
data[categorical_cols] = cat_imputer.fit_transform(data[categorical_cols])

categorical_columns = ['sex', 'cp', 'fbs', 'restecg', 'exang', 'slope', 'thal', 'dataset']
numerical_columns = ['age', 'trestbps', 'chol', 'thalch', 'oldpeak', 'ca']

X = data.drop(columns=['id', 'num'])
y = (data['num'] > 0).astype(int)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

preprocessor = ColumnTransformer(
    transformers=[
        ('num', StandardScaler(), numerical_columns), # ngubah agar fitur punya mean = 0 dan standar deviasi = 1
        ('cat', OneHotEncoder(handle_unknown='ignore'), categorical_columns)  # kategorikal ke numerik dalam bentuk biner
    ]
)

X_train = preprocessor.fit_transform(X_train)
X_test = preprocessor.transform(X_test)

# Synthetic Minority Oversampling Technique (mensintesis data baru untuk kelas yg lebih sedikit)
smote = SMOTE(random_state=42)
X_train_balanced, y_train_balanced = smote.fit_resample(X_train, y_train)

unique, counts = np.unique(y_train_balanced, return_counts=True)
print(unique, counts)
print(data['num'].value_counts())

print("Class distribution after SMOTE:", dict(zip(unique, counts)))

ann = MLPClassifier(
    hidden_layer_sizes=(128, 64, 32),
    activation='tanh',
    solver='adam',
    learning_rate_init=0.001,
    max_iter=500,
    random_state=42,
    early_stopping=True
)

ann.fit(X_train_balanced, y_train_balanced)

y_pred = ann.predict(X_test)
print("Classification Report:\n", classification_report(y_test, y_pred))
print("Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
# print("ROC-AUC Score:", roc_auc_score(y_test, ann.predict_proba(X_test)[:, 1]))

# ConfusionMatrixDisplay.from_estimator(ann, X_test, y_test)
# plt.title("Confusion Matrix")
# plt.show()

plt.plot(ann.loss_curve_)
plt.title("Loss Curve")
plt.xlabel("Epoch")
plt.ylabel("Loss")
# plt.show()
plt.savefig("loss_curve.jpg", format='jpg')

joblib.dump(ann, 'ann_heart_disease_model.pkl')
