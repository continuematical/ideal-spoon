import 'package:dio/dio.dart';
import 'package:shop/Page/Member/EntityFactory.dart';
import 'Model/HotEntity.dart';

Dio dio = Dio();

const HOT_URL = '/goods/searchHot';

class HotGoodsDao {
  static Future<HotEntity?> fetch() async {
    try {
      Response response = await dio.get(HOT_URL);
      if(response.statusCode == 200){
        return EntityFactory.generateOBJ<HotEntity>(response.data);
      }else{
        throw Exception("StatusCode: ${response.statusCode}");
      }
    } catch (e) {
      print(e);
      return null;
    }
  }
}
