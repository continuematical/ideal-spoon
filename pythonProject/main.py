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
    transfer = CountVectorizer()
    data_new = transfer.fit_transform(data)
    print("data_new:\n", data_new)
    return None


count_demo()