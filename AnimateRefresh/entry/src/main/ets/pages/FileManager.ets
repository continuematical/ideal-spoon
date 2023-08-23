import CommonConstants from '../common/constants/CommonConstants'
import RefreshComponent from '../View/RefreshComponent'

@Component
export struct FileManager {
  @Builder ContentBody() {

  }

  build() {
    Stack() {
      Text($r('app.string.file_index_title'))
        .backgroundColor(Color.White)
        .height(CommonConstants.FULL_LENGTH)
        .fontSize($r('app.float.file_index_title_size'))
        .fontWeight(FontWeight.Regular)
        .padding({
          left: $r('app.float.file_index_title_padding')
        })
        .zIndex(CommonConstants.FILE_MANAGER_Z_INDEX)
      //z序控制
      //在Stack中默认最后的元素堆叠在最上面，如果设置zIndex，zIndex值大的放在最上面

      RefreshComponent()
    }
    .height(CommonConstants.FULL_LENGTH)
  }
}