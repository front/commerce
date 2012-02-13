<script type="text/javascript">
    
    google.setOnLoadCallback(drawProductsPercentChart);
    
    function drawProductsPercentChart() {
        var data = new google.visualization.DataTable();
        data.addColumn('string', 'Beer');
        data.addColumn('number', 'Qty');
       
        data.addRows(<?php print count($data['qty']); ?>);
        
        <?php
        $c = 0;
        foreach ($data['qty'] as $b => $v){
            print "data.setValue(".$c.", 0, '".addslashes($b)."');\n";
            print "data.setValue(".$c.", 1, ".$v.");\n";
            $c++;
        }
        ?>
        
        var chart = new google.visualization.PieChart(document.getElementById('productspercentchart_div'));
        var options = {
              'title':'Product Percentages',
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
        <h2>Product Sales Percentages<a>+</a></h2>
    </header>
    <div id="productspercentchart_div"></div>
</section>