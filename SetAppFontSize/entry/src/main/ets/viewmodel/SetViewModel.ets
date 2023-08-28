import ChatData from '../common/bean/ChatData'
import { ItemDirection } from '../common/bean/ItemDirection'

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
}

export default new SetViewModel()