<script type="text/javascript">
    
    google.setOnLoadCallback(drawProductsQtyChart);
    
    function drawProductsQtyChart() {
        var data = new google.visualization.DataTable();
        data.addColumn('string', 'Month');
        <?php
        foreach ($data['cols'] as $col) {
            print "data.addColumn('number', '". addslashes($col) ."');\n";
        }
        $cols = $data['cols'];
        unset($data['cols']);
        //data.addColumn('number', 'Froach');
        //data.addColumn('number', 'Cock O\' The Walk');
        //data.addColumn('number', 'Ceilidh');
        $col_count = count($cols);
        ?>
        data.addRows(<?php print count($data); ?>);
        <?php        
        $c1 = 0;
        foreach ($data as $m => $d){
            $c2 = 1;
            print "data.setValue(".$c1.", 0, '".$m."');\n";
            
            foreach ($cols as $v) {
                $val = (isset($data[$m]['qty'][$v])) ? $data[$m]['qty'][$v] : 0;
                print "data.setValue(".$c1.", ".$c2.", ".$val.");\n";
                $c2++;
            }
            $c1++;
        }
        ?>
        
        var chart = new google.visualization.LineChart(document.getElementById('productsqtychart_div'));
        var options = {
              'title':'Product Qtys',
              'width':880,
              'height':300,
              'chartArea':{left:100,top:10,width:600},
              'legend' : 'right'
          };
        chart.draw(data, options);
    }
</script>
<section class="commerce-reports-accordion">
    <header>
        <h2>Product Qtys<a>+</a></h2>
    </header>
    <div id="productsqtychart_div"></div>
</section>