@Entry
@Component
struct Index {
  controller: WebController = new WebController()
  @State webResult: string = ''

  build() {
    Column() {
      Text(this.webResult)
      Web({
        src: 'www.baidu.com',
        controller: this.controller
      })
        .onPageEnd((event) => {
          this.controller.runJavaScript({
            script: 'text()',
            callback: (result) => {
              this.webResult = result
            }
          })
        })
    }
  }
}