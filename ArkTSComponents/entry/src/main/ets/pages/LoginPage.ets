import CommonConstants from '../common/constants/CommonConstants'

@Component
struct LoginPage {
  @State password: string = '';
  @State account: string = '';
  @State isShowProgress: boolean = false;
  private timeOutId = null;

  build() {
    Column() {
      Image($r('app.media.logo'))
        .width($r('app.float.logo_image_size'))
        .height($r('app.float.logo_image_size'))
      Text($r('app.string.login_page'))
        .fontSize($r('app.float.page_title_text_size'))
        .fontWeight(FontWeight.Medium)
        .fontColor($r('app.color.title_text_color'))
      Text($r('app.string.login_more'))
        .fontSize($r('app.float.normal_text_size'))
        .fontColor($r('app.color.login_more_text_color'))
        .margin({
          top: $r('app.float.login_more_margin_top'),
          bottom: $r('app.float.login_more_margin_bottom')
        })

      TextInput({
        placeholder: $r('app.string.password')
      })
        .maxLength(CommonConstants.INPUT_PASSWORD_LENGTH)
        .type(InputType.Password)
        .onChange((value: string) => {

        })
    }
  }
}