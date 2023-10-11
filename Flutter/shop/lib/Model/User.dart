class UserEntity {
  late UserInfoModel userInfoModel;
  late MsgModel msgModel;

  UserEntity.fromJson(Map<String,dynamic> json){
    if(json['data'] != null){
      userInfoModel = UserInfoModel.fromJson(json);
    }else{
      msgModel = MsgModel.fromJson(json);
    }
  }
}

class UserInfoModel {
  late String avatar;
  late String mobile;
  late String nickname;
  late String id;
  late String gender;

  UserInfoModel(
      {required this.avatar,
      required this.mobile,
      required this.nickname,
      required this.id,
      required this.gender});

  UserInfoModel.fromJson(Map<String, dynamic> json) {
    avatar = json['avatar'];
    mobile = json['mobile'];
    nickname = json['nickname'];
    id = json['id'];
    gender = json['gender'];
  }
}

class MsgModel {
  late String msg;

  MsgModel({required this.msg});

  MsgModel.fromJson(Map<String, dynamic> json) {
    msg = json['msg'];
  }
}
