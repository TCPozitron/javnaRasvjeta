<html>
	<head>
		<!-- Latest compiled and minified CSS -->
		<link rel="stylesheet" href="css/bootstrap.min.css">

		<!-- jQuery library -->
		<script src="js/jquery.min.js"></script>

		<!-- Latest compiled JavaScript -->
		<script src="js/bootstrap.min.js"></script>
		
	
	
		<style>
		body {
			margin:0px;
			padding:0px;
			width:99%;
			 background-image: url("img/background.jpg");
		}
		
		.card {
			background-color: rgba(0,0,0,0.2);
			margin-top:10px;
			margin-right:15px;
			padding-top:15px;
		}
		
		</style>
	</head>
	

	<body>
		
	<div class="row">
		<div class="col-lg-12">
			<div class="col-lg-1"></div>
			
			<div class="col-lg-5 card">
				<div style="text-align:center;" id="status-img-1">
					<img style="width:64px;"  src="img/led-off.png" />
				</div>
				<div style="text-align:center;padding-top:10px;">
					<span style="color:white;font-weight:bold;">LED 1</span>
					<div style="font-size:20px;padding-top:20px;"><span style="color:white;">STATUS: </span><span id="status1" style="font-weight:bold;color:red;">OFF</span></div>
				</div>
				<div style="text-align:center;">
					<br>
					<div style="width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-success" onclick="startLed(1);">ON</div>
					<br><br>
					<div style="width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-warning" onclick="stopLed(1);">OFF</div>
				</div>
				
				<div style="text-align:center;">
					<div style="text-align:center;margin-top:25px;">
						<img src="img/regulation.png" style="width:40px;"/>
						<select id="regulationValue1">
							<option value="0">Odaberite vrijednost regulacije...</option>
							<option value="25">5%</option>
							<option value="25">25%</option>
							<option value="50">50%</option>
							<option value="75">75%</option>
						</select>
					</div>
					
					<div style="text-align:center;margin-top:25px;">
						<img src="img/time.png" style="width:40px;"/>
						<select id="regulationTime1">
							<option value="0">Odaberite vrijeme regulacije...</option>
							<option value="5000">5s</option>
							<option value="10000">10s</option>
							<option value="20000">20s</option>
							<option value="30000">30s</option>
						</select>
					</div>
					
					<div style="margin-bottom:20px;margin-top:25px;width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-primary" onclick="prepareRegulation(1);">START</div>
					
					<br>
					
				</div>
				
			</div>
			
			<div class="col-lg-5 card">
				<div style="text-align:center;" id="status-img-2">
					<img style="width:64px;"  src="img/led-off.png" />
				</div>
				<div style="text-align:center;padding-top:10px;">
					<span style="color:white;font-weight:bold;">LED 2</span>
					<div style="font-size:20px;padding-top:20px;"><span style="color:white;">STATUS: </span><span id="status2" style="font-weight:bold;color:red;">OFF</span></div>
				</div>
				<div style="text-align:center;">
					<br>
					<div style="width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-success" onclick="startLed(2);">ON</div>
					<br><br>
					<div style="width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-warning" onclick="stopLed(2);">OFF</div>
				</div>
				
				<div style="text-align:center;">
					<div style="text-align:center;margin-top:25px;">
						<img src="img/regulation.png" style="width:40px;"/>
						<select id="regulationValue2">
							<option value="0">Odaberite vrijednost regulacije...</option>
							<option value="25">5%</option>
							<option value="25">25%</option>
							<option value="50">50%</option>
							<option value="75">75%</option>
						</select>
					</div>
					
					<div style="text-align:center;margin-top:25px;">
						<img src="img/time.png" style="width:40px;"/>
						<select id="regulationTime2">
							<option value="0">Odaberite vrijeme regulacije...</option>
							<option value="5000">5s</option>
							<option value="10000">10s</option>
							<option value="20000">20s</option>
							<option value="30000">30s</option>
						</select>
					</div>
					
					<div style="margin-bottom:20px;margin-top:25px;width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-primary" onclick="prepareRegulation(2);">START</div>
					
					<br>
					
				</div>
				
			</div>
			
			
		</div>
	</div>
	<br><br><br>
	
	
	<div class="row">
		<div class="col-lg-12">
			<div class="col-lg-1"></div>
			
			<div class="col-lg-5 card">
				<div style="text-align:center;" id="status-img-3">
					<img style="width:64px;"  src="img/led-off.png" />
				</div>
				<div style="text-align:center;padding-top:10px;">
					<span style="color:white;font-weight:bold;">LED 3</span>
					<div style="font-size:20px;padding-top:20px;"><span style="color:white;">STATUS: </span><span id="status3" style="font-weight:bold;color:red;">OFF</span></div>
				</div>
				<div style="text-align:center;">
					<br>
					<div style="width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-success" onclick="startLed(3);">ON</div>
					<br><br>
					<div style="width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-warning" onclick="stopLed(3);">OFF</div>
				</div>
				
				<div style="text-align:center;">
					<div style="text-align:center;margin-top:25px;">
						<img src="img/regulation.png" style="width:40px;"/>
						<select id="regulationValue3">
							<option value="0">Odaberite vrijednost regulacije...</option>
							<option value="25">5%</option>
							<option value="25">25%</option>
							<option value="50">50%</option>
							<option value="75">75%</option>
						</select>
					</div>
					
					<div style="text-align:center;margin-top:25px;">
						<img src="img/time.png" style="width:40px;"/>
						<select id="regulationTime3">
							<option value="0">Odaberite vrijeme regulacije...</option>
							<option value="5000">5s</option>
							<option value="10000">10s</option>
							<option value="20000">20s</option>
							<option value="30000">30s</option>
						</select>
					</div>
					
					<div style="margin-bottom:20px;margin-top:25px;width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-primary" onclick="prepareRegulation(3);">START</div>
					
					<br>
					
				</div>
				
			</div>
			
			<div class="col-lg-5 card">
				<div style="text-align:center;" id="status-img-4">
					<img style="width:64px;"  src="img/led-off.png" />
				</div>
				<div style="text-align:center;padding-top:10px;">
					<span style="color:white;font-weight:bold;">LED 4</span>
					<div style="font-size:20px;padding-top:20px;"><span style="color:white;">STATUS: </span><span id="status4" style="font-weight:bold;color:red;">OFF</span></div>
				</div>
				<div style="text-align:center;">
					<br>
					<div style="width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-success" onclick="startLed(4);">ON</div>
					<br><br>
					<div style="width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-warning" onclick="stopLed(4);">OFF</div>
				</div>
				
				<div style="text-align:center;">
					<div style="text-align:center;margin-top:25px;">
						<img src="img/regulation.png" style="width:40px;"/>
						<select id="regulationValue4">
							<option value="0">Odaberite vrijednost regulacije...</option>
							<option value="25">5%</option>
							<option value="25">25%</option>
							<option value="50">50%</option>
							<option value="75">75%</option>
						</select>
					</div>
					
					<div style="text-align:center;margin-top:25px;">
						<img src="img/time.png" style="width:40px;"/>
						<select id="regulationTime4">
							<option value="0">Odaberite vrijeme regulacije...</option>
							<option value="5000">5s</option>
							<option value="10000">10s</option>
							<option value="20000">20s</option>
							<option value="30000">30s</option>
						</select>
					</div>
					
					<div style="margin-bottom:20px;margin-top:25px;width:30%;display:inline-block;cursor:pointer;" class="btn-lg btn-primary" onclick="prepareRegulation(4);">START</div>
					
					<br>
					
				</div>
				
			</div>
			
			
		</div>
	</div>
		
	
	</body>
	
	
	<script>
		var ledStatus1 = 0;
		var ledStatus2 = 0;
		var ledStatus3 = 0;
		var ledStatus4 = 0;
		var checkerLed = 0;
		
		function startLed(id){
			document.getElementById("status"+id+"").innerHTML = "ON";
			document.getElementById("status"+id+"").style.color = "rgb(0,255,0)";
			$("#status-img-"+id+"").html("");
			$("#status-img-"+id+"").append("<img src='img/led-on.png' />");
			
			if(id==1){ ledStatus1 = 1; }
			if(id==2){ ledStatus2 = 1; }
			if(id==3){ ledStatus3 = 1; }
			if(id==4){ ledStatus4 = 1; }
			
			$.ajax({
				url: "ajax/start.php?id="+id+"",
				method: "GET",
				dataType: 'json',
				success: function (result) {
					
				}
			});
		}
		
		function stopLed(id){
			
			if(id==1){ ledStatus1 = 0; }
			if(id==2){ ledStatus2 = 0; }
			if(id==3){ ledStatus3 = 0; }
			if(id==4){ ledStatus4 = 0; }
			
			document.getElementById("status"+id+"").innerHTML = "OFF";
			document.getElementById("status"+id+"").style.color = "red";
			$("#status-img-"+id+"").html("");
			$("#status-img-"+id+"").append("<img src='img/led-off.png' />");
			
			$.ajax({
				url: "ajax/stop.php?id="+id+"",
				method: "GET",
				dataType: 'json',
				success: function (result) {}
			});
			
			
			
		}
		
		function prepareRegulation(id){
			
			
			
			if(id==1) {
				if(ledStatus1==0){
					alert("Za regulaciju morate uključiti LED diodu!");
				}
				else {
					startRegulation(1);
				}
			}
			if(id==2) {
				if(ledStatus2==0){
					alert("Za regulaciju morate uključiti LED diodu!");
				}
				else {
					startRegulation(2);
				}
			}
			
			if(id==3) {
				if(ledStatus3==0){
					alert("Za regulaciju morate uključiti LED diodu!");
				}
				else {
					startRegulation(3);
				}
			}
			
			if(id==4) {
				if(ledStatus4==0){
					alert("Za regulaciju morate uključiti LED diodu!");
				}
				else {
					startRegulation(4);
				}
			}
			
			
			
		}
		
		function startRegulation(id){
			
			var regulationValue = document.getElementById("regulationValue"+id+"").value;
			var regulationTime = document.getElementById("regulationTime"+id+"").value;
			if(regulationValue>0 && regulationTime>0){
				
			
				$.ajax({
					url: "ajax/regulation.php?id="+id+"&regulationValue="+regulationValue+"&regulationTime="+regulationTime+"",
					method: "GET",
					dataType: 'json',
					success: function (result) {}
				});
			}
			else {
				alert("Morate odabrati vrijednost i vrijeme regulacije");
			}
		}
		
		$(document).ready( function () {
			$('#table1').DataTable();
		} );
	
	</script>
	
</html>