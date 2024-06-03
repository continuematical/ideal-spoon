"""
只是为了借助yolov5的环境训练分类器，随时可以删去
"""

import torch
# 工具库 包含数据库，模型，图片操作库，其他操作等
import torchvision
# 图片操作库
import torchvision.transforms as transforms

import matplotlib.pyplot as plt
import numpy as np

import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim

"""
定义卷积神经网络
"""


class Net(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(3, 6, 5)
        self.pool = nn.MaxPool2d(2, 2)
        self.conv2 = nn.Conv2d(6, 16, 5)
        self.fc1 = nn.Linear(16 * 5 * 5, 120)
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)

    def forward(self, x):
        x = self.pool(F.relu(self.conv1(x)))
        x = self.pool(F.relu(self.conv2(x)))
        x = torch.flatten(x, 1)  # flatten all dimensions except batch
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = self.fc3(x)
        return x


"""
准备数据集
"""
# 归一化
transforms = transforms.Compose([
    transforms.ToTensor(),
    transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))
])

batch_size = 4

# 读取cifar10训练集后并进行标准化后下载到./data中
trainSet = torchvision.datasets.CIFAR10(root='./data', train=True,
                                        download=True, transform=transforms)
# # 批量加载数据集
trainLoader = torch.utils.data.DataLoader(trainSet, batch_size=4,
                                          shuffle=True, num_workers=2)

testSet = torchvision.datasets.CIFAR10(root='./data', train=False,
                                       download=True, transform=transforms)
testLoader = torch.utils.data.DataLoader(testSet, batch_size=4,
                                         shuffle=False, num_workers=2)

# 数据集标签
classes = ("plane", "car", "bird", "cat", "deer", "dog", "frog", "horse", "ship", "truck")


def imshow(img):
    # 增强图片对比度
    img = img / 2 + 0.5
    npImg = img.numpy()
    # 图片显示，此处需要转置
    plt.imshow(np.transpose(npImg, (1, 2, 0)))
    plt.show()


if __name__ == "__main__":
    dataiter = iter(trainLoader)
    images, labels = next(dataiter)
    # show image
    imshow(torchvision.utils.make_grid(images))
    # print labels
    print(' '.join('%5s' % classes[labels[i]] for i in range(batch_size)))

    net = Net()
    # 定义loss函数和优化器
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.SGD(net.parameters(), lr=0.001, momentum=0.9)

    # 训练网络
    for epoch in range(2):
        running_loss = 0.0
        for i, data in enumerate(trainLoader, 0):
            inputs, labels = data
            optimizer.zero_grad()
            outputs = net(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()

            running_loss += loss.item()
            if i % 2000 == 1999:
                print(f'[{epoch + 1},{i + 1:5d}] loss:{running_loss / 2000:.3f}')
                running_loss = 0.0

    print('Finished Training')

    # 保存模型位置
    PATH = './cifar_net.pth'
    torch.save(net.state_dict(), PATH)

    # 测试
    dataiter = iter(testLoader)
    images, labels = next(dataiter)

    # print images
    imshow(torchvision.utils.make_grid(images))
    print('GroundTruth: ', ' '.join(f'{classes[labels[j]]:5s}' for j in range(4)))

    # 让神经网络预测上述图片的类别
    outputs = net(images)
    _, predicted = torch.max(outputs, 1)

    print('Predicted: ', ' '.join(f'{classes[predicted[j]]:5s}'
                                  for j in range(4)))

    # 查看在整个测试集上的表现
    correct = 0
    total = 0
    # since we're not training, we don't need to calculate the gradients for our outputs
    with torch.no_grad():
        for data in testLoader:
            images, labels = data
            # calculate outputs by running images through the network
            outputs = net(images)
            # the class with the highest energy is what we choose as prediction
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()

    print(f'Accuracy of the network on the 10000 test images: {100 * correct // total} %')

    # prepare to count predictions for each class
    correct_pred = {classname: 0 for classname in classes}
    total_pred = {classname: 0 for classname in classes}

    # again no gradients needed
    with torch.no_grad():
        for data in testLoader:
            images, labels = data
            outputs = net(images)
            _, predictions = torch.max(outputs, 1)
            # collect the correct predictions for each class
            for label, prediction in zip(labels, predictions):
                if label == prediction:
                    correct_pred[classes[label]] += 1
                total_pred[classes[label]] += 1

    # print accuracy for each class
    for classname, correct_count in correct_pred.items():
        accuracy = 100 * float(correct_count) / total_pred[classname]
        print(f'Accuracy for class: {classname:5s} is {accuracy:.1f} %')