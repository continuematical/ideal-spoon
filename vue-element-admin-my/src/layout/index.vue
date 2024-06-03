<template>
    <div :class="classObj" class="app-wrapper">
        <div v-if="device==='mobile'"/>
    </div>
</template>


<script>
export default{
    name: 'Layout',
    components:{

    },
    computed:{

    },
    methods:{
        handleClickOutside(){
            
        }
    }
}
</script>


<style>
</style>