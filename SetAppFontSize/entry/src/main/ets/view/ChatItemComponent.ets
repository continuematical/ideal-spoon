import ChatData from '../common/bean/ChatData'
import StyleConstants from '../common/constants/StyleConstants'

@Component
export default struct ChatItemComponent {
  private chatData: ChatData
  @Prop changeFontSize: number

  build() {
    Row() {

    }
    .alignItems(VerticalAlign.Top)
    .width(StyleConstants.FULL_WIDTH)
  }
}