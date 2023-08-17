import TaskItemBean from '../common/bean/TaskItemBean'

@Component
export default struct TargetListItem {
  private targetItem: TaskItemBean
  @State latestProgress: number = 0
  @State updateDate: string = ''

  @Builder getTargetItemView(){
    Row(){
      Text()

      Blank()

      Column(){
        
      }
    }
  }

  build() {
    Stack({
      alignContent: Alignment.Start
    }) {
      Column() {

      }
    }
  }
}