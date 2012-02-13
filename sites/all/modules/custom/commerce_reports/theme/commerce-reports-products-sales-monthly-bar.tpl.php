<script type="text/javascript">
    
    google.setOnLoadCallback(drawSalesMonthlyChart);
    
    function drawSalesMonthlyChart() {
        var data = new google.visualization.DataTable();
        data.addColumn('string', 'Month');
        data.addColumn('number', 'Sales (Amount)');
       
        data.addRows(<?php print count($data); ?>);
        
        <?php
        $c = 0;
        foreach ($data as $m => $d){
            print "data.setValue(".$c.", 0, '".$m."');\n";
            print "data.setValue(".$c.", 1, ".number_format($d,2).");\n";
            $c++;
        }
        ?>
        
        var chart = new google.visualization.ColumnChart(document.getElementById('salesmonthlychart_div'));
        var options = {
              'title':'Product Sales',
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
        <h2>Product Sales<a>+</a></h2>
    </header>
    <div id="salesmonthlychart_div"></div>
</section>