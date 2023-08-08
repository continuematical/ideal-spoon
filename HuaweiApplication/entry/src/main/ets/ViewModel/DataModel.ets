import constants from '../Common/constants'

//数据基类
export class DataModel {
  private task: Array<string> = constants.TODO_DATA;

  getData(): Array<string> {
    return this.task;
  }
}

export default new DataModel();