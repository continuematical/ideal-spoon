import ChatData from '../common/bean/ChatData'
import { ItemDirection } from '../common/bean/ItemDirection'
import CommonConstants from '../common/constants/CommonConstants'

export class SetViewModel {
  chatArr: Array<ChatData> = null

  initChatData(): Array<ChatData> {
    if (this.chatArr === null) {
      this.chatArr = new Array

      let data = new ChatData()
      data.itemDirection = ItemDirection.RIGHT
      data.content = $r('app.string.set_chat_content1')
      this.chatArr.push(data)

      data = new ChatData()
      data.itemDirection = ItemDirection.LEFT
      data.content = $r('app.string.set_chat_content2')
      this.chatArr.push(data)

      data = new ChatData()
      data.itemDirection = ItemDirection.RIGHT
      data.content = $r('app.string.set_chat_content3')
      this.chatArr.push(data)

      data = new ChatData()
      data.itemDirection = ItemDirection.LEFT
      data.content = $r('app.string.set_chat_content4')
      this.chatArr.push(data)
    }
    return this.chatArr
  }

  getTextByFontSize(fontSize: number): Resource {
    let fontSizeText: Resource | string = ''
    switch (fontSize) {
      case CommonConstants.SET_SIZE_SMALL:
        fontSizeText = $r('app.string.set_size_small')
        break
      case CommonConstants.SET_SIZE_NORMAL:
        fontSizeText = $r('app.string.set_size_normal')
        break
      case CommonConstants.SET_SIZE_LARGE:
        fontSizeText = $r('app.string.set_size_large')
        break
      case CommonConstants.SET_SIZE_EXTRA_LARGE:
        fontSizeText = $r('app.string.set_size_extra_large')
        break
      case CommonConstants.SET_SIZE_HUGE:
        fontSizeText = $r('app.string.set_size_huge')
        break
      default:
        fontSizeText = $r('app.string.set_size_normal')
    }
    return fontSizeText
  }
}

export default new SetViewModel()