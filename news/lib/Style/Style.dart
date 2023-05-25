import 'dart:ui';

class StandardTextStyle {
  static TextStyle? big = TextStyle(
    fontWeight: FontWeight.w600,
    fontSize: SysSize.big,
  );

  static TextStyle? bigWithOpacity = TextStyle(
    fontWeight: FontWeight.w600,
    fontSize: SysSize.big,
    color: const Color.fromRGBO(0xff, 0xff, 0xff, 66),
  );

  static TextStyle? selectBig = TextStyle(
    fontWeight: FontWeight.w600,
    fontSize: SysSize.big,
    decoration: TextDecoration.underline,
  );

  static TextStyle? normal = TextStyle(
    fontWeight: FontWeight.normal,
    fontSize: SysSize.normal,
  );

  static TextStyle? normalWithOpacity = TextStyle(
    fontWeight: FontWeight.normal,
    fontSize: SysSize.normal,
    color: const Color.fromRGBO(0xff, 0xff, 0xff, 66),
  );

  static TextStyle? small = TextStyle(
    fontWeight: FontWeight.normal,
    fontSize: SysSize.small,
  );

  static TextStyle? smallWithOpacity = TextStyle(
    fontWeight: FontWeight.normal,
    fontSize: SysSize.small,
    color: const Color.fromRGBO(0xff, 0xff, 0xff, 66),
  );
}

class SysSize {
  static const double avatar = 56;

  // static const double iconBig = 40;
  static const double iconNormal = 24;

  // static const double big = 18;
  // static const double normal = 16;
  // static const double small = 12;
  static const double iconBig = 40;
  static const double big = 16;
  static const double normal = 14;
  static const double small = 12;
}

class ColorPlate {
  // 配色
  static const Color orange = Color(0xffFFC459);
  static const Color yellow = Color(0xffF1E300);
  static const Color green = Color(0xff7ED321);
  static const Color red = Color(0xffEB3838);
  static const Color darkGray = Color(0xff4A4A4A);
  static const Color gray = Color(0xff9b9b9b);
  static const Color lightGray = Color(0xfff5f5f4);
  static const Color black = Color(0xff000000);
  static const Color white = Color(0xffffffff);
  static const Color clear = Color(0x00000000);

  /// 深色背景
  static const Color back1 = Color(0xff1D1F22);

  /// 比深色背景略深一点
  static const Color back2 = Color(0xff121314);
}
