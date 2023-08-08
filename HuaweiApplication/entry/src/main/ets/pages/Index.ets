import DataModel from '../ViewModel/DataModel';
import constants from '../Common/constants'
import ToDoItem from '../View/ToDoItem';

@Entry
@Component
struct Index {
  private totalTask: Array<string> = [];

  aboutToAppear() {
    this.totalTask = DataModel.getData();
  }

  build() {
    Column({ space: constants.COLUMN_SPACE }) {
      Text($r('app.string.app_name'))
        .fontSize($r('app.float.title_font_size'))
        .fontWeight(FontWeight.Bold)
        .lineHeight($r('app.float.title_font_height'))
        .width(constants.TITLE_WIDTH)
        .margin({
          top: $r('app.float.title_margin_top'),
          bottom: $r('app.float.title_margin_bottom')
        })
        .textAlign(TextAlign.Start)

      ForEach(this.totalTask, (item) => {
        ToDoItem({ content: item })
      }, item => JSON.stringify(item))
    }
    .width(constants.FULL_LENGTH)
    .height(constants.FULL_LENGTH)
    .backgroundColor($r('app.color.page_background'))
  }
}