import pandas as pd
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.model_selection import train_test_split
from imblearn.over_sampling import SMOTE
from sklearn.svm import SVC
from sklearn.metrics import classification_report, confusion_matrix, roc_auc_score, ConfusionMatrixDisplay
import matplotlib.pyplot as plt
import joblib

file_path = 'heart_disease_uci.csv'
data = pd.read_csv(file_path)

text_to_number = {
    "four -eight": 48
}
data['age'] = data['age'].replace(text_to_number)
data['age'] = pd.to_numeric(data['age'], errors='coerce')

numerical_cols = ['age', 'trestbps', 'chol', 'thalch', 'oldpeak', 'ca']
categorical_cols = ['fbs', 'restecg', 'slope', 'thal', 'exang']

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
        ('num', StandardScaler(), numerical_columns), # ngubah spya mean = 0 dan standar deviasi = 1
        ('cat', OneHotEncoder(handle_unknown='ignore'), categorical_columns)  # kategorikal ke numerik dalam bentuk biner
    ]
)

X_train = preprocessor.fit_transform(X_train)
X_test = preprocessor.transform(X_test)

smote = SMOTE(random_state=42)
X_train_balanced, y_train_balanced = smote.fit_resample(X_train, y_train)

# radial basis function, data input dari ruang fitur asli ke ruang fitur berdimensi lebih tinggi secara non-linear, 
# untuk menangani data yang tidak dapat dipisahkan secara linear.

svm = SVC(kernel='rbf', probability=True, random_state=42)
svm.fit(X_train_balanced, y_train_balanced)

y_pred = svm.predict(X_test)
print("Classification Report:\n", classification_report(y_test, y_pred))

joblib.dump(svm, 'svm_heart_disease_model.pkl')
