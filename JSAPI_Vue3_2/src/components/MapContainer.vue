<template>
  <div id="container"></div>
</template>

<script setup>
  import { onMounted, onUnmounted } from "vue";
  import AMapLoader from "@amap/amap-jsapi-loader";

  let map=null, position=null
  //地图        //个人位置      
  let markers=[]//周围景点

  onMounted(() => {
    AMapLoader.load({
      key: "5faf651005374137d0c1f493eb2d7a53", // 申请好的Web端开发者Key，首次调用 load 时必填
      version: "2.0", // 指定要加载的 JSAPI 的版本，缺省时默认为 1.4.15
      plugins: ["AMap.Scale","AMap.ToolBar","AMap.HawkEye"], //需要使用的的插件列表，如比例尺'AMap.Scale'，支持添加多个如：['...','...']
      Loca:{
        version:'2.0.0'
      }
      //是否加载Loca，缺省不加载
    })
      .then((AMap) => {
        map = new AMap.Map("container", {
          // 设置地图容器id
          viewMode: "3D", // 是否为3D地图模式
          zoom: 11, // 初始化地图级别
          center: [116.397428, 39.90923], // 初始化地图中心点位置
          mapStyle:'amap://styles/grey'
        });

        //加载热力图
        createLocaHeatmap()

        //添加插件
        //map.addControl(new AMap.HawkEye())
        map.addControl(new AMap.Scale())
        
        //获取个人定位
        getlocation(AMap)

        //景点标记
        //initInterests()
        //createInterestMarker(AMap)
      })
      .catch((e) => {
        console.log(e);
      });
    });

  onUnmounted(()=>{
    map?.destroy()
  })

  //创建Loca热力图
  //Loca 2.0.0 API
  //https://lbs.amap.com/api/loca-v2/api
  function createLocaHeatmap(){
    var loca=new Loca.Container({map})
    var geo=new Loca.GeoJSONSource({
      url:"https://a.amap.com/Loca/static/loca-v2/demos/mock_data/traffic.json"
    })
    var heatMap=new Loca.HeatMapLayer({
      zIndex:10,
      opacity:1,
      visible:true,
      zooms:[2,22]
    })
    heatMap.setSource(geo,{
      radius:200000,
      unit:'meter',
      height:500000,
      gradient:{
        0.1: '#2A85B8',
        0.2: '#16B0A9',
        0.3: '#29CF6F',
        0.4: '#5CE182',
        0.5: '#7DF675',
        0.6: '#FFF100',
        0.7: '#FAA53F',
        1: '#D04343',
      },
      value:function(index, feature){
        return feature.properties.avg;
        var value=feature.properties.mom.slice(0,-1)
        return value+10*Math.random()
      },
      heightBezier:[0,.53,.37,.98]
    })
    loca.add(heatMap)
  }

  //添加点标记
  function addMarkers(AMap){
    //点标记显示内容
    const markerContent = `<div class="custom-content-marker">
    <img src="//a.amap.com/jsapi_demos/static/demo-center/icons/dir-via-marker.png">
    <div class="close-btn" onclick="clearMarker()">X</div>
    </div>`
    const marker=new AMap.Marker({
      position:position,
      //content:markerContent,
      //设置偏移量
      offset:new AMap.Pixel(-13,-30)
    })
    marker.setMap(map)
  }

  //获取定位
  function getlocation(AMap){
    AMap.plugin('AMap.Geolocation', function(){
      var geolocation = new AMap.Geolocation({
        // 是否使用高精度定位，默认：true
        enableHighAccuracy: true,
        // 设置定位超时时间，默认：无穷大
        timeout: 10000
      })

      //进行城市IP查询
      geolocation.getCityInfo(function(status, results){
        if(status=='complete'){
          console.log( "城市IP查询",results)
        }else{
          onError(results)
        }
      })

      //获取用户当前的精确位置信息
      geolocation.getCurrentPosition(function(status, results){
        if(status=='complete'){
          console.log("精确位置信息",results)
          position=results.position
          addMarkers(AMap)//个人定位标记
          map.setCenter(position, true)//设置地图中心点
          //表示立刻跳转到中心点坐标
        }else{
          onError(results)
          //获取失败，使用另一个方式定位
          this.getLngLatLocation(AMap)
        }
      })
    })
    
    //错误信息日志记录
    function onError(data){
      console.log("~ file: AboutView.vue ~ line 72 ~ onError ~ _data", data)
    }
  }

  //只获取城市级别的定位信息
  function getLngLatLocation(AMap){
      AMap.plugin('AMap.CitySearch', function(){
        var CitySearch=new AMap.CitySearch()
        CitySearch.getLocalCity(function(status, results){
          if(status=='complete' && results.info=='OK'){
            console.log("通过IP获取当前城市：", results)
            //逆向地理编码查询地理详细信息
            AMap.plugin('AMap.Geolocation', function(){
              var geocoder=new AMap.Geocoder({
                city:results.adcode
              })
              var lnglat=results.rectangle.split(';')[0].split(',')
              geocoder.getAddress(lnglat, function(status, data){
                if(status=='complete' && data.info==='OK'){
                  console.log("地理位置",data)
                }
              })
            })
          }
        })
      })
  }

  //放置景点marker
  const createInterestMarker=(AMap)=>{
    markers.forEach(function(marker){
      let markerss=new AMap.Marker({
        map:map,
        content:`<div class="${marker.in}" style='color: red;'></div>`,
        position:[marker.position[0], marker.position[1]],
        offset:new AMap.Pixel(-13,-30)
      })

      markerss.setLabel({
        direction:"center",
        offset:new AMap.Pixel(-13,-30),
        content:`<div class='info'>${marker.content}</div>`
      })

      markerss.setMap(map)
    })
  }

  //自定义城市景点数据
  function initInterests(){
    markers.push({
      position:[114.35537,30.53926],
      in:"alert",
      content:"武汉大学珞珈山"
    })

    markers.push({
      position:[114.340959,30.532157],
      in:"alert",
      content:"宝通寺"
    })
  }
</script>

<style scoped>
  /*地图容器样式 */
  #container {
    width: 100%;
    height: 100vh;
  }

  /*自定义点标记*/
  .custom-content-marker {
    position: relative;
    width: 25px;
    height: 34px;
  }

  .custom-content-marker img {
    width: 100%;
    height: 100%;
  }

  .custom-content-marker .close-btn {
    position: absolute;
    top: -6px;
    right: -8px;
    width: 15px;
    height: 15px;
    font-size: 12px;
    background: #ccc;
    border-radius: 50%;
    color: #fff;
    text-align: center;
    line-height: 15px;
    box-shadow: -1px 1px 1px rgba(10, 10, 10, .2);
  }

  .custom-content-marker .close-btn:hover{
    background: #666;
  }


  /*景点标注点样式 */
  .alert{
    display: inline-block;
    width: 8px;
    height: 8px;
    border-radius: 50%;
    background: #FF0000;
    margin: auto 5px;
    animation: animation_interset 1s infinite;
  }

  /*高德地图标注动画 */
  @keyframes animation_interest{
    0% {
      -moz-box-shadow: 0px 0px 10px 5px #ff0000;
      box-shadow: 0px 0px 10px 5px #ff0000;
    }
    50% {
      -moz-box-shadow: 0px 0px 20px 5px #ff0000;
      box-shadow: 0px 0px 20px 5px #ff0000;
    }
    100% {
      -moz-box-shadow: 0px 0px 10px 5px #ff0000;
      box-shadow: 0px 0px 10px 5px #ff0000;
    }
    150% {
      -moz-box-shadow: 0px 0px 50px 5px #ff0000;
      box-shadow: 0px 0px 50px 5px #ff0000;
    }
  }
</style>
