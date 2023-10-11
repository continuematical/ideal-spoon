
import 'package:flutter/material.dart';
import 'package:flutter_screenutil/flutter_screenutil.dart';

class AppSize {
  static void init(BuildContext context) {
    ScreenUtil.init(context, designSize: const Size(1080, 1920));
  }

  static double height(double value) {
    return ScreenUtil().setHeight(value).toDouble();
  }

  static double width(double value) {
    return ScreenUtil().setWidth(value).toDouble();
  }

  static double sp(double value) {
    return ScreenUtil().setSp(value).toDouble();
  }
}
