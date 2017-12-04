<?php $skins = gavias_mdeal_get_predefined_param('skins'); ?>

<div class="gavias-skins-panel">
	<div class="control-panel"><i class="fa fa-cogs"></i></div>
	<div class="panel-skins-content">
		<div class="title">Color skins</div>
		<div class="text-center">
		<a class="item-color default" data-skin="default"></a>
			<?php foreach ($skins as $key => $skin) { ?>
				<a class="item-color <?php echo $key; ?>" data-skin="<?php echo $key; ?>"></a>
			<?php } ?>
		</div>
	</div>

	<div class="clearfix"></div>

	<div class="panel-skins-content">
		<div class="title">Body layout</div>
		<div class="text-center">
			<a class="layout" data-layout="boxed">Boxed</a>
			<a class="layout" data-layout="wide">Wide</a>
		</div>
	</div>
</div>

<script>
	 var gavias_dir_theme = "<?php echo (base_path() . drupal_get_path('theme', 'gavias_mdeal')) ?>" ;
</script>

