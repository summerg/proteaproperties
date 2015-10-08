<li>
	<a class="btn btn-outline" href="#" data-filter=".<?php print strtolower(preg_replace('/[^a-z0-9.]+/i', '', $fields['name']->content)); ?>">
		<?php print $fields['name']->content; ?> one-<?php print preg_replace("/[^a-z0-9.]+/i", "",  strip_tags($fields['name']->value));?>-two
	</a>
	<?//var_dump(get_object_vars($fields['name']));?>
</li>