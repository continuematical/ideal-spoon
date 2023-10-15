import math


def datasets_demo():
    """
    数据集使用
    :return:
    """
    from sklearn.datasets import load_iris
    from sklearn.model_selection import train_test_split

    # 获取数据集
    iris = load_iris()
    print("鸢尾花数据集：\n", iris)
    print("鸢尾花数据集描述：\n", iris['DESCR'])
    print("查看特征值的名字：\n", iris.feature_names)
    print("查看特征值：\n", iris.data, iris.data.shape)

    # 划分数据集
    x_train, x_text, y_train, y_text = train_test_split(iris.data, iris.target, test_size=0.2, random_state=22)
    return None


def dict_demo():
    """
    字典特征提取
    :return:
    """

    from sklearn.feature_extraction import DictVectorizer
    data = [{'city': "北京", 'tem': 100}, {'city': "上海", 'tem': 60},
            {'city': "广州", 'tem': 40}, {'city': '长安', 'tem': 80}]
    # 实例化一个转化器类
    # 不返回稀疏矩阵
    transfer = DictVectorizer(sparse=False)
    data_new = transfer.fit_transform(data)
    print("转换后的结果为：", data_new)
    print("特征名字：", transfer.get_feature_names_out())
    return None


def count_demo():
    """
    文本特征抽取
    :return:
    """
    from sklearn.feature_extraction.text import CountVectorizer
    data = {"life is short, I like python", "life is long, I dislike python"}
    # 不能设置sparse=False
    # 统计每个样本特征值出现的个数
    transfer = CountVectorizer()
    data_new = transfer.fit_transform(data)
    print("data_new:\n", data_new)
    print("array:\n", data_new.toarray())
    print("特征名字：\n", transfer.get_feature_names_out())
    return None


def count_chinese_demo():
    """
    文本特征抽取
    :return:
    """
    from sklearn.feature_extraction.text import CountVectorizer
    data = {"我喜欢你", "我爱你"}
    # 不能设置sparse=False
    # 统计每个样本特征值出现的个数
    transfer = CountVectorizer()
    data_new = transfer.fit_transform(data)
    print("data_new:\n", data_new)
    print("array:\n", data_new.toarray())
    print("特征名字：\n", transfer.get_feature_names_out())
    return None


def min_max_demo():
    """
    归一化 Max_Min
    :return:
    """
    import pandas as pd
    from sklearn.preprocessing import MinMaxScaler
    # 获取文件
    data = pd.read_csv("dating.txt")
    print("data:\n", data)
    # 实例化一个转换器类
    transfer = MinMaxScaler()
    min_max_data = transfer.fit_transform(data)
    # numpy array格式的数据，返回转换后形状相同的array
    print("new_data:\n", min_max_data)


def standard_demo():
    """
    实现中心化 Z-score
    :return:
    """
    import pandas as pd
    from sklearn.preprocessing import StandardScaler
    # 获取文件
    data = pd.read_csv("dating.txt")
    print("data:\n", data)
    # 实例化一个转换器类
    transfer = StandardScaler()
    score_data = transfer.fit_transform(data)
    print("new_data:\n", score_data)


def merge_demo():
    import pandas as pd
    import numpy as np
    # 定义df1
    df1 = pd.DataFrame({'alpha': ['A', 'B', 'B', 'C', 'D', 'E'],
                        'beta': ['a', 'a', 'b', 'c', 'c', 'e'],
                        'feature1': [1, 1, 2, 3, 3, 1],
                        'feature2': ['low', 'medium', 'medium', 'high', 'low', 'high']})
    # 定义df2
    df2 = pd.DataFrame({'alpha': ['A', 'A', 'B', 'F'],
                        'fruit': ['apple', 'orange', 'pine', 'pear'],
                        'kilo': ['high', 'low', 'high', 'medium'],
                        'price': np.array([5, 6, 5, 7])},
                       index=['d', 'd', 'b', 'f'])
    df3 = pd.merge(df1, df2, left_on='beta', right_index=True)
    print(df3)


def join_demo():
    """
    基于 index 连接表
    :return:
    """
    import pandas as pd
    df1 = pd.DataFrame({'key': ['K0', 'K1', 'K2', 'K3', 'K4', 'K5'],
                        'A': ['A0', 'A1', 'A2', 'A3', 'A4', 'A5']})
    df2 = pd.DataFrame({'key': ['K0', 'K1', 'K2'],
                        'B': ['B0', 'B1', 'B2']})
    df3 = df1.join(df2, lsuffix="_new", rsuffix="_new", how="outer")
    print(df1)
    print(df2)
    print(df3)


def concat_demo():
    import pandas as pd
    df1 = pd.Series([1.1, 2.2, 3.3], index=['i1', 'i2', 'i3'])
    df2 = pd.Series([4.4, 5.5, 6.6], index=['i2', 'i3', 'i4'])
    df3 = pd.concat([df1, df2], axis=1)
    print(df1)
    print(df2)
    print(df3)


def combine_first_demo():
    import numpy as np
    import pandas as pd
    df1 = {"ID": [1, 2, 3, 4, 5, 6, 7, 8, 9],
           "System": ['win7', 'win8', np.nan, 'win9', np.nan, np.nan, 'win10', 'win7', 'win8'],
           'CPU': ['i5', 'i7', np.nan, 'i7', np.nan, np.nan, 'i5', 'i7', 'i3']}
    df2 = {"ID": [1, 2, 3, 4, 5, 6, 7, 8, 9],
           'System': ['win7', np.nan, np.nan, np.nan, 'win10', 'win7', np.nan, np.nan, np.nan],
           'CPU': ['i3', np.nan, 'i5', np.nan, 'i7', 'i5', np.nan, np.nan, np.nan]}
    df1 = pd.DataFrame(df1)
    df2 = pd.DataFrame(df2)
    df3 = df1.combine_first(df2)
    print(df1)
    print(df2)
    print(df3)


def text():
    import pandas as pd
    import numpy as np
    order = pd.read_excel("one.xlsx")
    provide = pd.read_excel("one2.xlsx")
    data = pd.DataFrame(index=range(402), columns=range(240))

    for i in range(order.shape[0]):
        for j in range(order.shape[1]):
            if order.iloc[i, j] < provide.iloc[i, j]:
                data.iloc[i, j] = 1
            else:
                data.iloc[i, j] = 0


def prac():
    import pandas as pd
    data = pd.read_excel("超市营业额数据.xlsx")
    # 将工号的整数类型转化为字符型
    data['工号'] = data['工号'].apply(lambda x: str(x))
    # 查看数据基本信息
    # print(data.describe())

    # 查看重复数据
    # print(data[data.duplicated()])

    # 删除重复数据
    data.drop_duplicates()

    # 将缺失的交易额用每个员工所有的交易额中值进行补充
    for i in data[data['交易额'].isnull()].index:
        data.loc[i, "交易额"] = round(data.loc[data.姓名 == data.loc[i, "姓名"], '交易额'].median())

    # 改变交易额
    data.loc[data['交易额'] < 500, '交易额'] = 500
    data.loc[data['交易额'] > 3000, '交易额'] = 3000

    # 所有员工工号前面加上一个数
    # 深拷贝
    from copy import deepcopy
    deep_copy_data = deepcopy(data)
    new_num = lambda x: str(x)[-1] + str(x)
    deep_copy_data['new_number'] = deep_copy_data[['工号']].applymap(new_num)
    print(deep_copy_data)


def index_demo():
    import pandas as pd
    import numpy as np
    data = pd.Series(np.random.randn(9),
                     index=[['a', 'a', 'a', 'b', 'b', 'c', 'c', 'd', 'd'], [1, 2, 3, 1, 3, 1, 2, 2, 3]])
    # print(data)
    # print(data.index)

    # 将数据安排到 DataFrame 中
    # print(data.unstack())

    frame = pd.DataFrame(np.arange(12).reshape(4, 3), index=[['a', 'a', 'b', 'b'], [1, 2, 1, 2]]
                         , columns=[['Oh', 'Oh', 'Color'], ['Green', 'Green', 'Red']])
    # 命名
    frame.index.names = ['key1', 'key2']
    frame.columns.names = ['state', 'color']

    # 级别和名称呼唤
    frame.swaplevel('key1', 'key2')

    # 根据单个级别的值进行排序
    frame.sort_index(level=1)

    # 级别汇总统计
    # sum
    print(frame.sum(level='color', axis=1))


# number 数据集
def create_answer(number_set, n):
    import random
    """
    创建解集
    :return:
    """
    # 产生随机解
    result = []
    for i in range(n):
        result.append(random.sample(number_set, 10))


# new_answer解
def error_level(new_answer, number_set):
    error = []
    right_answer = sum(number_set) / 10
    for i in new_answer:
        value = abs(right_answer - sum(i))
        if value == 0:
            error.append(0)
        else:
            error.append(1 / value)
    return error


def choice_selected(old_answer, number_set):
    """
    选择优秀的交换：误差越小的解选择的几率越大，归一化
    :return:
    """
    import random
    # 计算误差系数
    error = error_level(old_answer, number_set)
    error_one = [item / sum(error) for item in error]

    # 叠加
    for i in range(1, len(error_one)):
        error_one[i] += error_one[i - 1]
    for i in range(len(old_answer) // 2):
        temp = []
        for j in range(2):
            rand = random.uniform(0, 1)
            # 在error_one 中进行寻找
            for k in range(len(error_one)):
                if k == 0:
                    if rand < error_one[k]:
                        temp.append(old_answer[k])

                else:
                    if old_answer[k - 1] <= rand < old_answer[k]:
                        temp.append(old_answer[k])
    return


def GA():
    import random

    # 随机生成结果
    number_set = random.sample(range(0, 1000), 50)
    middle_set = create_answer(number_set, 100)
    # 循环一千次
    for i in range(1000):
        middle_set = choice_selected()
    print(middle_set)
    return


def PCA():
    import pandas as pd
    import numpy as np
    # 读取数据集
    df = pd.read_excel("aa.xlsx")
    # 进行球状检验
    from factor_analyzer.factor_analyzer import calculate_bartlett_sphericity
    chi_square_value, p_value = calculate_bartlett_sphericity(df)
    # print(chi_square_value, p_value)

    # KMO相关性分析
    from factor_analyzer.factor_analyzer import calculate_kmo
    kmo_per_variable, kmo_all = calculate_kmo(df)
    # print(kmo_per_variable, kmo_all)

    # 数据不标准化
    # 求平均值
    average = np.mean(df, axis=0)
    # 列数和行数
    m, n = np.shape(df)
    # 均值矩阵
    data_adjust = []
    av = np.tile(average, (m, 1))
    # 对数据集进行去中心化
    data_adjust = df - av
    # 计算协方差矩阵
    corr_two = np.cov(data_adjust.T)
    # 求解特征值和向量值
    featValue, featVec = np.linalg.eig(corr_two)

    # 对特征值进行输出并排序
    featValue = sorted(featValue)[::-1]

    # 绘制散点图和折线图
    import matplotlib.pyplot as plt
    plt.scatter(range(1, df.shape[1] + 1), featValue)
    plt.plot(range(1, df.shape[1] + 1), featValue)

    # 显示图得标题和 xy 轴的名字
    plt.title("Screen Plot")
    plt.xlabel("Factors")
    plt.ylabel("Eigenvalue")

    plt.grid()
    # plt.show()

    # 求特征值的贡献度
    gx = featValue / np.sum(featValue)
    # print(gx)

    # 求特征值的累计贡献度
    lg = np.cumsum(gx)
    # print(lg)

    # 选出主成分
    k = [i for i in range(len(lg)) if lg[i] < 0.85]
    k = list(k)
    # print(k)

    # 选出主成分对应的特征向量矩阵
    selectVec = np.matrix(featVec.T[k]).T
    selectVec = selectVec * (-1)
    # print(selectVec)

    # 求主成分得分
    finalData = np.dot(data_adjust, selectVec)
    # print(finalData)

    # 绘制热力图
    import seaborn as sns
    plt.figure(figsize=(14, 14))
    ax = sns.heatmap(selectVec, annot=True, cmap="BuPu")

    # 设置y轴字体大小
    ax.yaxis.set_tick_params(labelsize=15)
    plt.title("Factor Analysis", fontsize="xx-large")

    # 设置y轴标签
    plt.ylabel("Sepal Width", fontsize="xx-large")
    # 显示图片
    # plt.show()

    # 保存图片
    # plt.savefig("factorAnalysis", dpi=500)


def CA():
    """
    聚类分析
    :return:
    """
    # https://blog.csdn.net/tonydz0523/article/details/84659905
    from sklearn.datasets import make_blobs
    from sklearn import metrics
    import pandas as pd

    # 数据准备
    data = make_blobs(n_samples=2000, centers=[[1, 1], [-1, -1]], cluster_std=0.7, random_state=2018)
    x = data[0]
    y = data[1]
    # 聚类数量
    number_cluster = 2
    from sklearn.cluster import KMeans
    # 建立聚类模型对象
    k_means = KMeans(random_state=2018, n_clusters=number_cluster)
    k_means.fit(x)  # 训练
    pre_y = k_means.predict(x)  # 预测
    # 模型效果评估
    # 样本距离最近的聚类中心的总和
    inertia = k_means.inertia_
    # 调整后的兰德指数
    adjust_rand_s = metrics.adjusted_rand_score(y, pre_y)
    # 互信息
    mutual_info_s = metrics.mutual_info_score(y, pre_y)

    # 调整后的互信息
    adjusted_mutual_info_s = metrics.adjusted_mutual_info_score(y, pre_y)

    # 同质化得分
    homogeneity_s = metrics.homogeneity_score(y, pre_y)

    # 完整性得分
    completeness_s = metrics.completeness_score(y, pre_y)

    # V-measure得分
    v_measure_s = metrics.v_measure_score(y, pre_y)

    # 平均轮廓系数
    silhouette_s = metrics.silhouette_score(x, pre_y, metric='euclidean')

    # Calinski 和 Harabaz 得分
    calinski_harabaz_s = metrics.calinski_harabaz_score(x, pre_y)

    df_metrics = pd.DataFrame([[inertia, adjust_rand_s, mutual_info_s, adjusted_mutual_info_s, homogeneity_s,
                                completeness_s, v_measure_s, silhouette_s, calinski_harabaz_s]],
                              columns=['ine', 'tARI', 'tMI', 'tAMI', 'thomo', 'tcomp', 'tv_m', 'tsilh', 'tc&h'])


# DBSCAN

import numpy as np


# 读取文件
def load_file(fileName, spiltChar='\t'):
    dataset = []
    with open(fileName) as fr:
        for line in fr.readlines():
            curLine = line.strip().split(spiltChar)
            fltLine = list(map(float, curLine))
            dataset.append(fltLine)
    return dataset


# 计算两个点之间的欧氏距离
def dist(t1, t2):
    dis = math.sqrt(np.power((t1[0] - t2[0]), 2) + np.power((t1[1] - t2[1]), 2))
    return dis


def dbscn(data, Eps, MinPoint):
    num = len(data)
    # 标记点是否被访问过
    unvisited = [i for i in range(num)]
    visited = []
    C = [-1 for _ in range(num)]  # 输出结果
    k = -1  # 标记不同的簇
    while len(unvisited) > 0:
        p = np.random.choice(unvisited)
        unvisited.remove(p)
        visited.append(p)
        # N为p的epsilon领域中对象的集合
        N = []
        for i in range(num):
            if dist(data[i], data[p]) <= Eps:
                N.append(i)
        # 如果p的epsilon邻域中的对象数大于指定阈值，说明p是一个核心对象
        if len(N) >= MinPoint:
            k = k + 1
            C[p] = k
            # 对于领域内每个对象pi
            for pi in N:
                if pi in unvisited:
                    unvisited.remove(pi)
                    visited.append(pi)
                    # M是pi领域中的对象
                    M = []
                    for j in range(num):
                        if dist(data[j], data[pi]) <= Eps:
                            M.append(pi)
                    if len(M) > MinPoint:
                        for t in M:
                            if t not in N:
                                N.append(t)
                if C[pi] == -1:
                    C[pi] = k
        else:
            C[p] = -1
    return C


def clique_demo():
    from pyclustering.cluster.clique import clique
    # clique可视化
    from pyclustering.cluster.clique import clique_visualizer
    import numpy as np
    # 构建训练数据集
    f1 = np.array([37, 42, 49, 56, 61, 65])
    f2 = np.array([147, 154, 161, 165, 172, 177])
    f3 = np.array([450, 780, 1000, 324, 455, 578])

    data = np.array([f1, f2, f3])
    data = data.T

    data_M = np.array(data)
    intervals = 5  # 定义每个维度中网格单元的数量
    threshold = 0  # 设定的阈值
    clique_instance = clique(data_M, intervals, threshold)
    # 开始聚类过程
    clique_instance.process()
    clique_cluster = clique_instance.get_clusters()
    # 被认为是噪声点
    noise = clique_instance.get_noise()
    # clique形成的网格单元
    cells = clique_instance.get_cells()

    print(len(clique_cluster))
    print(clique_cluster)

    # 聚类结果可视化
    clique_visualizer.show_grid(cells, data_M)
    # 显示聚类结果
    clique_visualizer.show_clusters(data_M, clique_cluster, noise)


def prc():
    from pyclustering.cluster.clique import clique, clique_visualizer
    from pyclustering.utils import read_sample
    from pyclustering.samples.definitions import FCPS_SAMPLES
    # read two-dimensional input data 'Target'
    data = read_sample(FCPS_SAMPLES.SAMPLE_TARGET)
    interval = 10
    threshold = 0
    clique_instance = clique(data, interval, threshold)
    # start clustering process and obtain results
    clique_instance.process()
    clusters = clique_instance.get_clusters()  # allocated clusters
    noise = clique_instance.get_noise()  # points that are considered as outliers (in this example should be empty)
    cells = clique_instance.get_cells()  # CLIQUE blocks that forms grid
    print("Amount of clusters:", len(clusters))
    # visualize clustering results
    clique_visualizer.show_grid(cells, data)  # show grid that has been formed by the algorithm
    clique_visualizer.show_clusters(data, clusters, noise)  # show clustering results

prc()
