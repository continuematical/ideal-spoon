import ChatData from '../common/bean/ChatData'
import { ItemDirection } from '../common/bean/ItemDirection'
import StyleConstants from '../common/constants/StyleConstants'

@Component
export default struct ChatItemComponent {
  private chatData: ChatData
  @Prop changeFontSize: number

  build() {
    Row() {
      Image(this.chatData.itemDirection === ItemDirection.RIGHT
        ? $r('app.media.right_head') : $r('app.media.left_head'))
        .width(StyleConstants.SET_CHAT_HEAD_SIZE_PERCENT)
        .aspectRatio(StyleConstants.HEAD_ASPECT_RATIO)
        .margin({
          left: this.chatData.itemDirection === ItemDirection.RIGHT
            ? StyleConstants.HEAD_LEFT_PERCENT : StyleConstants.HEAD_RIGHT_PERCENT,
          right: this.chatData.itemDirection === ItemDirection.RIGHT
            ? StyleConstants.HEAD_RIGHT_PERCENT : StyleConstants.HEAD_LEFT_PERCENT
        })

      ChatContent({
        item: this.chatData,
        changeFontSize: this.changeFontSize,
      })
    }
    .alignItems(VerticalAlign.Top)
    .width(StyleConstants.FULL_WIDTH)
    .margin({
      top: StyleConstants.CHAT_TOP_MARGIN_PERCENT
    })
    .direction(this.chatData.itemDirection === ItemDirection.RIGHT
      ? Direction.Rtl : Direction.Ltr)
  }
}

@Component
struct ChatContent {
  item: ChatData
  @Prop changeFontSize: number
  @State isLineFeed: boolean = false

  build() {
    Row() {
      Text(this.item.content)
        .fontColor($r('app.color.text'))
        .fontSize(this.changeFontSize + StyleConstants.UNIT_FP)
        .fontWeight(FontWeight.Medium)
        .onAreaChange((oldValue: Area, newValue: Area) => {
          this.isLineFeed = newValue.height > StyleConstants.DOUBLE_ROW_MIN
        })

      if (this.isLineFeed)
        Blank().layoutWeight(StyleConstants.WEIGHT_FULL)
    }
    .constraintSize({
      maxWidth: StyleConstants.MAX_CHAT_WIDTH_PERCENT,
    })
    .direction(Direction.Ltr)
    .padding({
      left: $r('app.float.set_chat_content_vertical_padding'),
      right: $r('app.float.set_chat_content_vertical_padding'),
      top: $r('app.float.set_chat_content_horizontal_padding'),
      bottom: $r('app.float.set_chat_content_horizontal_padding')
    })
    .backgroundColor(this.item.itemDirection === ItemDirection.RIGHT
      ? $r('app.color.set_chat_right_bg') : $r('app.color.set_chat_left_bg'))
    .borderRadius($r('app.float.set_chat_content_bg_radius'))
  }
}