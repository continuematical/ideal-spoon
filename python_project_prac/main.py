import math

import waveCluster


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


def naive():
    from sklearn.datasets import load_iris
    from sklearn.model_selection import train_test_split
    from sklearn.naive_bayes import GaussianNB
    import matplotlib.pyplot as plt
    iris = load_iris()
    X = iris.data
    y = iris.target
    # 拆分数据集为训练集和测试集
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
    # 创建贝叶斯分类器对象
    classifier = GaussianNB()
    # 训练分类器
    classifier.fit(X_train, y_train)
    # 生成测试机预测结果
    # y_predict为预测的分类
    y_predict = classifier.predict(X_test)
    # 绘制分类结果
    plt.scatter(X_test[:, 0], X_test[:, 1], c=y_test, cmap="viridis")
    plt.xlabel('Sepal Length')
    plt.ylabel('Sepal Width')
    plt.title('Classification Results on Text Set')
    plt.show()


# 遗传算法
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D

DNA_SIZE = 24
POP_SIZE = 80
CROSSOVER_RATE = 0.6
MUTATION_RATE = 0.01
N_GENERATIONS = 100
X_BOUND = [-2.048, 2.048]
Y_BOUND = [-2.048, 2.048]


def F(x, y):
    return 100.0 * (y - x ** 2.0) ** 2.0 + (1 - x) ** 2.0  # 以香蕉函数为例


def plot_3d(ax):
    X = np.linspace(*X_BOUND, 100)
    Y = np.linspace(*Y_BOUND, 100)
    X, Y = np.meshgrid(X, Y)
    Z = F(X, Y)
    ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm)
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_zlabel('z')
    plt.pause(3)
    plt.show()


def get_fitness(pop):
    x, y = translateDNA(pop)
    pred = F(x, y)
    return pred
    # return pred - np.min(pred)+1e-3  # 求最大值时的适应度
    # return np.max(pred) - pred + 1e-3  # 求最小值时的适应度，通过这一步fitness的范围为[0, np.max(pred)-np.min(pred)]


def translateDNA(pop):  # pop表示种群矩阵，一行表示一个二进制编码表示的DNA，矩阵的行数为种群数目
    x_pop = pop[:, 0:DNA_SIZE]  # 前DNA_SIZE位表示X
    y_pop = pop[:, DNA_SIZE:]  # 后DNA_SIZE位表示Y

    x = x_pop.dot(2 ** np.arange(DNA_SIZE)[::-1]) / float(2 ** DNA_SIZE - 1) * (X_BOUND[1] - X_BOUND[0]) + X_BOUND[0]
    y = y_pop.dot(2 ** np.arange(DNA_SIZE)[::-1]) / float(2 ** DNA_SIZE - 1) * (Y_BOUND[1] - Y_BOUND[0]) + Y_BOUND[0]
    return x, y


def crossover_and_mutation(pop, CROSSOVER_RATE=0.8):
    new_pop = []
    for father in pop:  # 遍历种群中的每一个个体，将该个体作为父亲
        child = father  # 孩子先得到父亲的全部基因（这里我把一串二进制串的那些0，1称为基因）
        if np.random.rand() < CROSSOVER_RATE:  # 产生子代时不是必然发生交叉，而是以一定的概率发生交叉
            mother = pop[np.random.randint(POP_SIZE)]  # 再种群中选择另一个个体，并将该个体作为母亲
            cross_points = np.random.randint(low=0, high=DNA_SIZE * 2)  # 随机产生交叉的点
            child[cross_points:] = mother[cross_points:]  # 孩子得到位于交叉点后的母亲的基因
        mutation(child)  # 每个后代有一定的机率发生变异
        new_pop.append(child)

    return new_pop


def mutation(child, MUTATION_RATE=0.003):
    if np.random.rand() < MUTATION_RATE:  # 以MUTATION_RATE的概率进行变异
        mutate_point = np.random.randint(0, DNA_SIZE)  # 随机产生一个实数，代表要变异基因的位置
        child[mutate_point] = child[mutate_point] ^ 1  # 将变异点的二进制为反转


def select(pop, fitness):  # nature selection wrt pop's fitness
    idx = np.random.choice(np.arange(POP_SIZE), size=POP_SIZE, replace=True,
                           p=(fitness) / (fitness.sum()))
    return pop[idx]


def print_info(pop):
    fitness = get_fitness(pop)
    max_fitness_index = np.argmax(fitness)
    print("max_fitness:", fitness[max_fitness_index])
    x, y = translateDNA(pop)
    print("最优的基因型：", pop[max_fitness_index])
    print("(x, y):", (x[max_fitness_index], y[max_fitness_index]))
    print(F(x[max_fitness_index], y[max_fitness_index]))


def color_bar():
    import matplotlib.pyplot as plt
    import numpy as np

    vegetables = ["cucumber", "tomato", "lettuce", "asparagus",
                  "potato", "wheat", "barley"]
    farmers = ["Farmer Joe", "Upland Bros.", "Smith Gardening",
               "Agrifun", "Organiculture", "BioGoods Ltd.", "Cornylee Corp."]

    harvest = np.array([[0.8, 2.4, 2.5, 3.9, 0.0, 4.0, 0.0],
                        [2.4, 0.0, 4.0, 1.0, 2.7, 0.0, 0.0],
                        [1.1, 2.4, 0.8, 4.3, 1.9, 4.4, 0.0],
                        [0.6, 0.0, 0.3, 0.0, 3.1, 0.0, 0.0],
                        [0.7, 1.7, 0.6, 2.6, 2.2, 6.2, 0.0],
                        [1.3, 1.2, 0.0, 0.0, 0.0, 3.2, 5.1],
                        [0.1, 2.0, 0.0, 1.4, 0.0, 1.9, 6.3]])

    plt.xticks(np.arange(len(farmers)), labels=farmers,
               rotation=45, rotation_mode="anchor", ha="right")
    plt.yticks(np.arange(len(vegetables)), labels=vegetables)
    plt.title("Harvest of local farmers (in tons/year)")

    for i in range(len(vegetables)):
        for j in range(len(farmers)):
            text = plt.text(j, i, harvest[i, j], ha="center", va="center", color="w")

    plt.imshow(harvest)
    plt.colorbar()
    plt.tight_layout()
    plt.show()


# if __name__ == "__main__":
#     fig = plt.figure()
#     ax = Axes3D(fig)
#     plt.ion()  # 将画图模式改为交互模式，程序遇到plt.show不会暂停，而是继续执行
#     plot_3d(ax)
#
#     pop = np.random.randint(2, size=(POP_SIZE, DNA_SIZE * 2))  # matrix (POP_SIZE, DNA_SIZE)
#     for _ in range(N_GENERATIONS):  # 迭代N代
#         x, y = translateDNA(pop)
#         if 'sca' in locals():
#             sca.remove()
#         sca = ax.scatter(x, y, F(x, y), c='black', marker='o')
#         plt.show()
#         plt.pause(0.1)
#         pop = np.array(crossover_and_mutation(pop, CROSSOVER_RATE))
#         fitness = get_fitness(pop)
#         pop = select(pop, fitness)  # 选择生成新的种群
#
#     print_info(pop)
#     plt.ioff()
#     plot_3d(ax)


# 模拟退火算法求解TSP

# 31个城市的坐标
city_loc = [(1304, 2312), (3639, 1315), (4177, 2244), (3712, 1399), (3488, 1535),
            (3326, 1556), (3238, 1229), (4196, 1004), (4312, 790), (4380, 570),
            (3007, 1970), (2562, 1756), (2788, 1491), (2381, 1676), (1332, 695),
            (3715, 1678), (3918, 2179), (4061, 2370), (3780, 2212), (3676, 2578),
            (4029, 2838), (4263, 2931), (3429, 1908), (3507, 2367), (3394, 2643),
            (3439, 3201), (2935, 3240), (3140, 3550), (2545, 2357), (2778, 2826), (2370, 2975)]

T_0 = 50000  # 初始温度
T_end = 15  # 结束温度
k = 0.98  # 比例系数
N = 1000  # 迭代次数


# 求解两个城市的距离
def dist(a, b):
    x1 = city_loc[a][0]
    y1 = city_loc[a][1]
    x2 = city_loc[b][0]
    y2 = city_loc[b][1]
    distance = ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5
    return distance


# 初始化解
def init_ans():
    ans = []
    for i in range(31):
        ans.append(i)
    return ans


# 路程总长
def total_distance(a):
    value = 0
    for j in range(30):
        value += dist(a[j], a[j + 1])
    value += dist(a[0], a[30])
    return value


# 迭代过程
def create_new(ans_before):
    ans_after = []
    for i in range(len(ans_before)):
        ans_after.append(ans_before[i])
    cityA = np.random.randint(0, 30)
    cityB = np.random.randint(0, 30)
    # 随机交换两个城市的坐标
    ans_after[cityA], ans_after[cityB] = ans_after[cityB], ans_after[cityA]
    return ans_after


# if __name__ == '__main__':
#     ans0 = init_ans()
#     T = T_0
#     cnt = 0
#     trend = []  # 保存迭代的每一次路线
#     while T > T_end:
#         for i in range(N):
#             new_ans = create_new(ans0)
#             old_dist = total_distance(ans0)
#             new_dist = total_distance(ans0)
#             df = new_dist - old_dist
#             if df >= 0:
#                 rand = np.random.uniform(0, 1)
#                 if rand < 1 / (math.exp(df / T)):
#                     ans0 = new_ans
#             else:
#                 ans0 = new_ans
#         T = T * k
#         cnt += 1
#         now_dist = total_distance(ans0)
#         trend.append(now_dist)
#     distance = total_distance(ans0)
#     print(distance, ans0)
#     plt.plot(trend)
#     plt.show()

from datetime import datetime


def prac():
    fig, ax = plt.subplots()
    data = pd.read_csv("stock_px.csv", parse_dates=True, index_col=0)
    spx = data['SPX']
    spx.plot(ax=ax, color='black')
    crisis_data = [
        (datetime(2007, 10, 11), 'Peak of bull market'),
        (datetime(2008, 3, 12), 'bear Stearn Fails'),
        (datetime(2008, 9, 15), 'Lehman Bankruptcy')
    ]

    for date, label in crisis_data:
        ax.annotate(label, xy=(date, spx.asof(date) + 75),
                    xytext=(date, spx.asof(date) + 225),
                    arrowprops=dict(facecolor="black", headwidth=4, width=2,
                                    headlength=4),
                    horizontalalignment="left", verticalalignment="top")

    # Zoom in on 2007-2010
    ax.set_xlim(["1/1/2007", "1/1/2011"])
    ax.set_ylim([600, 1800])

    ax.set_title("Important dates in the 2008–2009 financial crisis")
    plt.show()


def draw_map():
    fig, ax = plt.subplots()

    rect = plt.Rectangle((0.2, 0.75), 0.4, 0.15, color="black", alpha=0.3)
    circ = plt.Circle((0.7, 0.2), 0.15, color="blue", alpha=0.3)
    pgon = plt.Polygon([[0.15, 0.15], [0.35, 0.4], [0.2, 0.6]],
                       color="green", alpha=0.5)

    ax.add_patch(rect)
    ax.add_patch(circ)
    ax.add_patch(pgon)

    plt.show()


def B():
    # 初始化参数
    D_0 = 70  # 中心点的海水深度
    theta = 120
    alpha = 1.5
    d = 200
    d = d * np.sin(np.radians(90 - theta / 2)) / np.sin(np.radians(90 - alpha + theta / 2))
    distance = np.array([-800, -600, -400, -200, 0, 200, 400, 600, 800])
    D = D_0 - distance * np.tan(np.radians(alpha))

    W = D * np.sin(np.radians(theta / 2)) * (
            1 / np.sin(np.radians((180 - theta) / 2 + alpha)) + 1 / np.sin(np.radians((180 - theta) / 2 - alpha)))
    n = 1 - d / W
    data = pd.DataFrame({'测线距中心点处的距离/m': distance})
    data['海水深度/m'] = D
    data['覆盖宽度/m'] = W
    data['与前一条测线的重叠率/%'] = n
    print(data)
    return


coins = [5, 6, 4, 8]
n = len(coins)
dp = [[0] * (n + 2) for _ in range(n + 2)]
print(dp)
