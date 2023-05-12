import 'package:flutter/material.dart';

import '../AppSize.dart';

class ThemeView {
  static Widget divider({Orientation orientation = Orientation.landscape}) {
    if (orientation == Orientation.landscape) {
      return const Divider(height: 0.0, color: Color(0xffdedede));
    } else {
      return const VerticalDivider(
        width: 0.0,
        color: Color(0xffdedede),
      );
    }
  }
}

class ThemeTextStyle{
  static final primaryStyle = TextStyle(fontSize: AppSize.sp(44),color: const Color(0xff333333));
  static final primaryStyle2 = TextStyle(fontSize: AppSize.sp(44),color: const Color(0xff656565));
  static final menuStyle = TextStyle(fontSize: AppSize.sp(36),color: const Color(0xff666666));
  static final menuStyle2 = TextStyle(fontSize: AppSize.sp(36),color: const Color(0xff656565));
  static final menuStyle3 = TextStyle(fontSize: AppSize.sp(36),color: const Color(0xff333333));
  static final priceStyle = TextStyle(fontSize: AppSize.sp(32),color: const Color(0xffee4646));
  static final cardTitleStyle = TextStyle(fontSize: AppSize.sp(40),color: const Color(0xff333333));
  static final cardPriceStyle = TextStyle(fontSize: AppSize.sp(35),color: const Color(0xffee4646));
  static final cardNumStyle = TextStyle(fontSize: AppSize.sp(32),color: const Color(0xff999999));
  static final orderFormStatusStyle = TextStyle(fontSize: AppSize.sp(38),color: const Color(0xff999999));
  static final orderFormTitleStyle = TextStyle(fontSize: AppSize.sp(38),color: const Color(0xff333333));
  static final orderFormBtnStyle = TextStyle(fontSize: AppSize.sp(44),color: ThemeColor.appBarTopBg);
  static final orderCancelBtnStyle = TextStyle(fontSize: AppSize.sp(44),color: const Color(0xff999999));
  static final orderContentStyle = TextStyle(fontSize: AppSize.sp(36),color: const Color(0xff999999));
  static final personalShopNameStyle = TextStyle(fontSize: AppSize.sp(52),color: const Color(0xff333333));
  static final detailStyle = TextStyle(fontSize: AppSize.sp(44),color: const Color(0xff999999));
  static final detailStylePrice = TextStyle(fontSize: AppSize.sp(44),color: const Color(0xffee4646));
  static final orderStylePrice = TextStyle(fontSize: AppSize.sp(44),color: const Color(0xffffffff));
  static final personalNumStyle = TextStyle(
      fontSize: AppSize.sp(44),
      color: ThemeColor.appBarTopBg,
      fontWeight: FontWeight.w700);

  static final primaryBoldStyle = TextStyle(
      fontSize: AppSize.sp(44),
      color: const Color(0xff333333),
      fontWeight: FontWeight.w700);
}

class ThemeColor {
  static const Color appBg = Color(0xfff5f6f7);
  static const Color appBarTopBg = Color(0xff00C2FD);
  static const Color appBarBottomBg = Color(0xff00C2FD);
  static const Color hintTextColor = Color(0xff333333);
  static const Color subTextColor = Color(0xff999999);
  static const Color starColor = Color(0xFFFFA516);
  static const Color loginColor = Color(0xFFFE976A);
}
