import constants from '../Common/constants'

@Component
export default struct ToDoItem {
  private content: string;
  @State isCompleted: boolean = false;

  @Builder LabelIcon(icon) {
    Image(icon)
      .objectFit(ImageFit.Contain)
      .width($r('app.float.checkbox_width'))
      .height($r('app.float.checkbox_width'))
      .margin($r('app.float.checkbox_margin'))
  }

  build() {
    Row() {
      if (this.isCompleted) {
        this.LabelIcon($r('app.media.ic_ok'))
      } else {
        this.LabelIcon($r('app.media.ic_default'))
      }

      Text(this.content)
        .fontSize($r('app.float.item_font_size'))
        .fontWeight(constants.FONT_WEIGHT)
        .opacity(this.isCompleted ? constants.OPACITY_COMPLETED : constants.OPACITY_DEFAULT)
        .decoration({
          type: this.isCompleted ? TextDecorationType.LineThrough : TextDecorationType.None
        })
        .borderRadius(constants.BORDER_RADIUS)
        .backgroundColor($r('app.color.start_window_background'))
        .width(constants.LIST_DEFAULT_WIDTH)
        .height($r('app.float.list_item_height'))
        .onClick(() => {
          this.isCompleted = !this.isCompleted
        })
    }
  }
}