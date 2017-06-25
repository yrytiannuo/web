(function($){
	var PageSwitch=(function(){
		function PageSwitch(element,options){
			this.settins=$.extend(true,$.fn.PageSwitch.default,options||{});
			this.element=element;
		}
	})();
	$.fn.PageSwitch=function(options){
		return this.each(function(){
			var me=$(this),
			instance=me.data("PageSwitch");
			if(!instance){
				instance=new PageSwitch(me,options);
				me.data("PageSwitch",instance);
			}
		});
	}
	$.fn.PageSwitch.default = {
		selectors:{
			sections :".sections",
			section : ".section",
			page : ".pages",
			active : ".active"
		},
		index:0,
		easing:"ease",
		duration : 500,
		loop : false,
		pagination : true,
		keyboard : true,
		direction : "vertical",
		callback : ""

	}
	}
