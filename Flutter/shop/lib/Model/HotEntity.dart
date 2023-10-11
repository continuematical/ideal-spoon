import 'Good.dart';

//推荐商品
class HotEntity {
  late List<GoodsModel> goods;

  HotEntity({required this.goods});

  HotEntity.fromJson(Map<String, dynamic> json) {
    if (json['data'] != null) {
      goods = <GoodsModel>[];
      List<Map<String, dynamic>> dataList = (json['data'] as List).cast();
      for (var element in dataList) {
        goods.add(GoodsModel.fromJson(element));
      }
    }
  }
}
