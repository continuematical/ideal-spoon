import './assets/main.css'

import { createApp } from 'vue'
import App from './App.vue'

//引入移动端调试工具
import VConsole from 'vconsole'

// 判断是否是pc设备
const isPc = () => {
    const userAgentInfo = navigator.userAgent;
    const Agents = ["Android", "iPhone",
        "SymbianOS", "Windows Phone",
        "iPad", "iPod"];
    let flag = true;
    for (let v = 0; v < Agents.length; v++) {
        if (userAgentInfo.indexOf(Agents[v]) > 0) {
            flag = false;
            break;
        }
    }
    return flag;
}
 
//如果不是生产环境并且不是pc设备那么就显示调试
if (process.env.NODE_ENV != "prod" && !isPc()) {
    console.log(process.env.NODE_ENV);
    const vConsole = new VConsole();
}

createApp(App).mount('#app')
