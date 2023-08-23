@Component
export default struct RefreshComponent {
  private listController: Scroller = new Scroller()

  aboutToAppear() {

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
        case TouchType.Move:
        case TouchType.Up:
        default :
          break;
      }
    })
  }
}