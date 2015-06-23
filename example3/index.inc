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
            <defs>
                <marker id="triangleFill" viewBox="0 0 8 8" refX="0" refY="4" markerWidth="32"
                        markerHeight="24" orient="auto" markerUnits="strokeWidth">
                    <path d="M 0 0 L 8 4 L 0 8 z"></path>
                </marker>    
                <marker id="triangleEmpty" viewBox="0 0 8 8" refX="0" refY="4" markerWidth="40"
                        markerHeight="30" orient="auto">
                    <path d="M 0 0 L 8 4 L 0 8 z" fill="transparent" stroke="black" stroke-width="0.5"></path>
                </marker>
                <marker id="triangleOpen" viewBox="0 0 8 8" refX="0" refY="4" markerWidth="40"
                        markerHeight="30" orient="auto">
                    <path d="M -4 0 L 0 4 L -4 8 " fill="transparent" stroke="black" stroke-width="0.5"></path>
                </marker>
            </defs>
            <g transform="translate(0 0)">
                <rect class="draggable"
                    x="0" y="0"
                    width="80" height="80"
                    fill="blue"
                    onmousedown="selectElement(evt)">
                </rect>
                <text x="0" y="20" fill="black" font-family="Verdana" font-size="24">Hello</text>
            </g>
        
            <path d="M 100 100 L 200 100" marker-end="url(#triangleFill)" stroke="black"></path>
            <path d="M 100 200 L 200 200" marker-end="url(#triangleEmpty)" stroke="black"></path>
            <path d="M 100 300 L 200 300" marker-end="url(#triangleOpen)" stroke="black"></path>
        </svg
        
    </body>
</html>
            