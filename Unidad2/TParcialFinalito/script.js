function viewGraph(){
	
var p1 = '79%';
var p2 = '51%';
var p3 = '45%';

document.getElementById("p1").innerHTML = p1;
document.getElementById("p2").innerHTML = p2;
document.getElementById("p3").innerHTML = p3;

$('.column').css('height','0');

$('table tr').each(function(index) {
var ha = $(this).children('td').eq(1).text();
$('#col'+index).animate({height: ha}, 1500).html("<div>"+ha+"</div>");

});
}

