<html>
<head>
    <title>Taha's localhost</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <link rel="stylesheet" href="../../../include/css/category.css">
    <script>
        $(document).ready(function(){
            $("button").click(function(){
                var id = $(this).attr('id');
                var num = $(this).attr('data-num');
                jQuery.ajax({
                    type: "POST",
                    url: "../../../category/add_like",
                    data: {id:id , num : num },
                    success : function(result){
                        if(result == 1){
                            num++;
                            $('button#' + id).attr('data-num', num);
                            $('button#' + id + '>span.JaLike').html(num);
                        }
                    }
                });
            });
        });
    </script>
</head>
<body>

</body>
</html>