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


prac()
