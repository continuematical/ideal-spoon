import HobbyBean from '../common/bean/HobbyBean'

@Component
export default struct CustomDialogWidget {
  @State hobbyBeans: HobbyBean[] = []

  build() {
    Column() {
      Text()

      List() {
        ForEach(this.hobbyBeans, (item: HobbyBean) => {
          ListItem() {
            Row(){

            }
            .height($r('app.float.options_height'))
            .margin({

            })
          }
        }, item => item.label)
      }

      Row() {
        Button()

        Blank()

        Button()
      }
    }
  }
}

@Extend(Button) function dialogButtonStyle() {
  .fontSize($r('app.float.button_text_size'))
  .fontColor($r('app.color.custom_button_color'))
}