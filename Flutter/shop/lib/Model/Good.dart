class GoodsEntity {
  late List<GoodsModel> goods;

  GoodsEntity({required this.goods});

  GoodsEntity.fromJson(Map<String, dynamic> json) {
    if (json['data'] != null) {
      goods = <GoodsModel>[];
      List<Map<String, dynamic>> dataList =
          (json['data']['records'] as List).cast();
      for (var element in dataList) {
        goods.add(GoodsModel.fromJson(element));
      }
    }
  }
}

//商品
class GoodsModel {
  late String createBy;
  late String createTime;
  late String description;
  late String detail;
  late String id;
  late String idCategory;

  late bool isDelete;
  late bool isOnSale;
  late String modifyBy;
  late String modifyTime;
  late String name;
  late int stock;
  late String picture;
  late int price;
  late String specifications;

  GoodsModel(
      {required this.createBy,
      required this.createTime,
      required this.description,
      required this.detail,
      required this.idCategory,
      required this.isDelete,
      required this.isOnSale,
      required this.modifyBy,
      required this.modifyTime,
      required this.name,
      required this.stock,
      required this.picture,
      required this.price,
      required this.specifications,
      required this.id});

  GoodsModel.fromJson(Map<String, dynamic> json) {
    createBy = json['createBy'];
    createTime = json['createTime'];
    description = json['description'];
    detail = json['detail'];
    idCategory = json['idCategory'];
    isDelete = json['isDelete'];
    isOnSale = json['isOnSale'];
    modifyBy = json['modifyBy'];
    modifyTime = json['modifyTime'];
    name = json['name'];
    if (json['stock'].toString().isEmpty) {
      stock = 0;
    } else {
      stock = int.parse(json['stock'].toString());
    }

    picture = json['pic'];

    if (json['price'].toString().isEmpty) {
      price = 0;
    } else {
      price = int.parse(json['price'].toString());
    }
    specifications = json['specifications'];
    id = json['id'];
  }
}
