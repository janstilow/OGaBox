 /* 
 * The MIT License (MIT)
 * Copyright (c) 2016 Arthur Kunst, Georg Stilow, Jan Stilow
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
 //TODO: INIT WEBSOCKET

var context = document.getElementById('can-draw').getContext("2d");
var mouseX = 0;
var mouseY = 0;
var mouseDown = false;

var scale = 1;

$(function()
{
    $(window).resize(function () { resize(); });
    init();
});

function init()
{

    context.canvas.width = DRAW_RESOLUTION;
    context.canvas.height = DRAW_RESOLUTION*ASPECT_RATIO;
    context.clearRect(0, 0, context.canvas.width, context.canvas.height);
    context.lineWidth = 7;
    context.strokeStyle = "#dd2222";
    context.lineJoin = "round";

    resize();
}

function resize()
{
    var wh = $(window).height()-($('#header').height()+$('#footer').height()+ 30);
    var ww = $(window).width()-30;
    var can = $("#can-draw");
    if(wh/ww>ASPECT_RATIO)
    {
        can.width(ww);
        can.height(ww*ASPECT_RATIO);
    }
    else
    {
        can.width(wh/ASPECT_RATIO);
        can.height(wh);
    }

    scale = can.width()/DRAW_RESOLUTION;
}

$('#can-draw').mousemove(function(e)
{
    if(mouseDown)
    {
        var mX = (e.clientX - this.offsetLeft)/scale;
        var mY = (e.clientY - this.offsetTop)/scale;
        drawline(mX,mY);
    }
});

$('#can-draw').on("touchmove", function(e)
{
    e.preventDefault();
    if(mouseDown)
    {
        var mX = (e.originalEvent.touches[0].pageX - this.offsetLeft)/scale;
        var mY = (e.originalEvent.touches[0].pageY - this.offsetTop)/scale;
        drawline(mX,mY); 
    }
});

$('#can-draw').mouseout(function(e)
{
    if(mouseDown)
    {
        var mX = (e.pageX - this.offsetLeft)/scale;
        var mY = (e.pageY - this.offsetTop)/scale;
        drawline(mX,mY);
    }
    mouseDown = false;
});

$('#can-draw').on("touchleave", function(e){
    alert("asd");
    if(mouseDown)
    {
        var mX = (e.originalEvent.touches[0].pageX - this.offsetLeft)/scale;
        var mY = (e.originalEvent.touches[0].pageY - this.offsetTop)/scale;
        drawline(mX,mY);
    }
    mouseDown = false;
});

$('#can-draw').mousedown(function(e)
{
    mouseDown = true;
    mouseX = (e.pageX - this.offsetLeft)/scale;
    mouseY = (e.pageY - this.offsetTop)/scale;
    drawpoint(mouseX,mouseY);
});

$('#can-draw').on("touchstart", function(e){
    mouseDown = true;
    mouseX = (e.originalEvent.touches[0].pageX - this.offsetLeft)/scale;
    mouseY = (e.originalEvent.touches[0].pageY - this.offsetTop)/scale;
});

$('#can-draw').mouseup(function()
{
    mouseDown = false;
});

$('#can-draw').on("touchend", function(){
    mouseDown = false;
});

function drawline(mX, mY)
{

    context.beginPath();
    context.moveTo(mouseX,mouseY);
    context.lineTo(mX,mY);
    context.closePath();
    context.stroke();

    console.log("x:" + mouseX + " to " + mX + " | y:" + mouseY + " to " + mY);

    mouseX = mX;
    mouseY = mY;
}

function drawpoint(mX, mY)
{

    context.beginPath();
    context.arc(mX,mY,1,0,2*Math.PI);
    context.fill(); 
    context.stroke();

    console.log("x:" + mouseX + " to " + mX + " | y:" + mouseY + " to " + mY);

    mouseX = mX;
    mouseY = mY;
}