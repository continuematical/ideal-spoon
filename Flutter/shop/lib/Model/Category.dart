import 'dart:convert';

class CategoryEntity {
  late List<CategoryModel> category;

  CategoryEntity({required this.category});

  CategoryEntity.fromJson(Map<String, dynamic> json){
    if (json['data'] != null) {
      category = <CategoryModel>[];
      for (var element in (json['data'] as List)) {
        category.add(CategoryModel.fromJson(element));
      }
    }
  }
}

class CategoryModel {
  late String name;
  late String id;
  late List<CategoryInfoModel> categoryInfoModels;

  CategoryModel(
      {required this.name, required this.id, required this.categoryInfoModels});

  factory CategoryModel.fromJson(Map<String, dynamic> parsedJson) {
    var list = parsedJson['bannerList'] as List;
    List<CategoryInfoModel> categoryInfoModel =
    list.map((e) => CategoryInfoModel.fromJson(e)).toList();
    return CategoryModel(
      id: parsedJson['id'],
      name: parsedJson['name'],
      categoryInfoModels: categoryInfoModel,
    );
  }
}

class CategoryInfoModel {
  late String createBy;
  late String createTime;
  late String idFile;
  late String modifyBy;
  late String modifyTime;
  late String title;
  late String type;
  late String url;
  late String id;
  late String page;
  late String param;

  CategoryInfoModel({required this.createBy,
    required this.createTime,
    required this.idFile,
    required this.modifyBy,
    required this.modifyTime,
    required this.title,
    required this.type,
    required this.url,
    required this.id,
    required this.page,
    required this.param});

  CategoryInfoModel.fromJson(Map<String, dynamic> json) {
    createBy = json['createBy'];
    createTime = json['createTime'];
    idFile = json['idFile'];
    modifyBy = json['modifyBy'];
    modifyTime = json['modifyTime'];
    title = json['title'];
    type = json['title'];
    url = json['url'];
    id = json['id'];
    page = json['page'];
    param = json['param'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> map = <String, dynamic>{};
    map['createBy'] = createBy;
    map['createTime'] = createTime;
    map['idFile'] = idFile;
    map['modifyBy'] = modifyBy;
    map['modifyTime'] = modifyTime;
    map['title'] = title;
    map['type'] = type;
    map['url'] = url;
    map['id'] = id;
    map['page'] = page;

    return map;
  }
}
