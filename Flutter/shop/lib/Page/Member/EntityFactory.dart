import 'package:shop/Model/Category.dart';
import 'package:shop/Model/Good.dart';
import 'package:shop/Model/HotEntity.dart';
import 'package:shop/Model/User.dart';

class EntityFactory{
  static T generateOBJ<T>(dynamic json){
    switch(T.toString()){
      case 'HotEntity':
        return HotEntity.fromJson(json) as T;
      case 'UserEntity':
        return UserEntity.fromJson(json) as T;
      case 'GoodsEntity':
        return GoodsEntity.fromJson(json) as T;
      case 'CategoryEntity':
        return CategoryEntity.fromJson(json) as T;
      default:
        return null as T;
    }
  }
}