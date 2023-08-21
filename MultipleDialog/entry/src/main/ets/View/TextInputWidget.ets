import CommonConstants from '../common/contants/CommonConstants'

@Component
export default struct TextInputWidget {
  private inputImage: Resource
  private hintText: string

  build() {
    Row() {
      Image(this.inputImage)
        .width($r('app.float.input_image_size'))
        .height($r('app.float.input_image_size'))

      TextInput({
        placeholder: this.hintText
      })
        .fontSize($r('app.float.input_text_size'))
    }
    .margin({
      top: $r('app.float.input_row_top')
    })
    .borderRadius($r('app.float.input_row_radius'))
    .backgroundColor(Color.White)
    .width(CommonConstants.COMMON_DIALOG_WIDTH)
    .height($r('app.float.input_row_height'))
  }
}