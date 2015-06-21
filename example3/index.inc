<!DOCTYPE html>
<html>
    <head>
    </head>
    <body>
        <script> 
          var selectedElement = 0;
          var currentX = 0;
          var currentY = 0;
          var translation = 0;

          function selectElement(evt) {
            selectedElement = evt.target.parentNode;
            currentX = evt.clientX;
            currentY = evt.clientY;
            var transform = selectedElement.getAttributeNS(null, "transform");
            var after_slice = transform.slice(10, -1);
            translation = selectedElement.getAttributeNS(null, "transform").slice(10,-1).split(' ');
            translation[0] = parseInt(translation[0]);
            translation[1] = parseInt(translation[1]);
    

            selectedElement.setAttributeNS(null, "onmousemove", "moveElement(evt)");
            //selectedElement.setAttributeNS(null, "onmouseout", "deselectElement(evt)");
selectedElement.setAttributeNS(null, "onmouseup", "deselectElement(evt)");
          }
          
          function moveElement(evt){
              dx = evt.clientX - currentX;
              dy = evt.clientY - currentY;
              translation[0] += dx;
              translation[1] += dy;
              //newMatrix = "matrix(" + currentMatrix.join(' ') + ")";

              selectedElement.setAttributeNS(null, "transform", "translate(" + translation[0] + " " + translation[1] +")");
              currentX = evt.clientX;
              currentY = evt.clientY;
            }
            
            function deselectElement(evt){
              if(selectedElement != 0){
                selectedElement.removeAttributeNS(null, "onmousemove");
                selectedElement.removeAttributeNS(null, "onmouseout");
                selectedElement.removeAttributeNS(null, "onmouseup");
                selectedElement = 0;
              }
            }
 </script>
        <svg width="640" height="480">
        <g transform="translate(0 0)">
        <rect class="draggable"
              x="30" y="30"
              width="80" height="80"
              fill="blue"
              onmousedown="selectElement(evt)"/>
       
        <text x="0" y="10" fill="black" font-family="Verdana" font-size="24">Hello</text>
        </g>
        </svg
        
    </body>
</html>
            