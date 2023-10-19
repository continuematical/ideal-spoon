import pandas as pd
from sklearn import cluster, preprocessing, datasets


def wave_cluster_wave_data():
    for i in range(4):
        df = pd.read_csv("waveData_{}.csv".format(i), header=None)
        data = df.iloc[:, :2].as_matrix()
        # 数据标准化
        data = preprocessing.MinMaxScaler().fit_transform(data)


def wave_cluster_iris():
    iris = datasets.load_iris()
    data = iris.data

def wave_cluster():
    return


def kmeans_data():
    return
