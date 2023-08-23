import { RefreshConstants, RefreshHeaderStyle, RefreshState } from '../common/constants/RefreshConstants'

@Component
export default struct RefreshComponent {
  private listController: Scroller = new Scroller()
  private headerStyle: RefreshHeaderStyle = RefreshHeaderStyle.DEFAULT
  private onRefresh: () => void
  private headerOffset: number = 0
  private displayHeight: number
  //状态
  @Consume(RefreshConstants.REFRESH_STATE_TAG) @Watch('onStateChange') state: number;
  @BuilderParam itemLayout: () => void

  aboutToAppear() {
    //正在刷新
    if (this.state === RefreshState.REFRESHING) {
      this.headerOffset = 0
      this.onStateChange()
    } else {
      this.state = RefreshState.IDLE
      this.headerOffset = -RefreshConstants.REFRESH_HEADER_HEIGHT
    }
    this.displayHeight += RefreshConstants.REFRESH_HEADER_HEIGHT
  }

  onStateChange() {
    switch (this.state) {
      case RefreshState.REFRESHING:
        if (this.onRefresh != null) {
          this.onRefresh
        }
        break
      case RefreshState.COMPILE:
        this.headerOffset = -RefreshConstants.REFRESH_HEADER_HEIGHT
        break
      default:
        break
    }
  }

  build() {
    List({
      scroller: this.listController
    }) {
      ListItem() {
        Column() {

        }
      }
    }
    .onTouch((event) => {
      switch (event.type) {
        case TouchType.Down:
          if (this.state === RefreshState.IDLE) {
            this.state = RefreshState.DRAGGING
          }
          break
        case TouchType.Move:
          if (this.state === RefreshState.DRAGGING &&
          this.listController.currentOffset().yOffset <= -RefreshConstants.REFRESH_EFFECTIVE_HEIGHT) {
            this.state = RefreshState.DRAGGING_REFRESHABLE
          }
          break
        case TouchType.Up:
          if (this.state === RefreshState.DRAGGING_REFRESHABLE) {
            this.headerOffset = 0
            this.state = RefreshState.REFRESHING
          }
        default:
          break;
      }
    })
  }
}