<!DOCTYPE html>
<html>
    <head>
    </head>
    <body>
        <svg width="640" height="480">
        <rect class="draggable"
              x="30" y="30"
              width="80" height="80"
              fill="blue"
              transform="matrix(1 0 0 1 0 0)"
              onmousedown="selectElement(evt)"/>
        </svg>
        <script> 
          var selectedElement = 0;
          var currentX = 0;
          var currentY = 0;
          var currentMatrix = 0;

          function selectElement(evt) {
            selectedElement = evt.target;
            currentX = evt.clientX;
            currentY = evt.clientY;
            currentMatrix = selectedElement.getAttributeNS(null, "transform").slice(7,-1).split(' ');

              for(var i=0; i<currentMatrix.length; i++) {
                currentMatrix[i] = parseFloat(currentMatrix[i]);
              }

            selectedElement.setAttributeNS(null, "onmousemove", "moveElement(evt)");
            selectedElement.setAttributeNS(null, "onmouseout", "deselectElement(evt)");
selectedElement.setAttributeNS(null, "onmouseup", "deselectElement(evt)");
          }
          
          function moveElement(evt){
              dx = evt.clientX - currentX;
              dy = evt.clientY - currentY;
              currentMatrix[4] += dx;
              currentMatrix[5] += dy;
              newMatrix = "matrix(" + currentMatrix.join(' ') + ")";

              selectedElement.setAttributeNS(null, "transform", newMatrix);
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
    </body>
</html>
            