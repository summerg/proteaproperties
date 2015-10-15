<li>
	<a class="btn btn-outline" href="#" data-filter=".<?php print preg_replace('/[^a-z]/', '', str_replace("&amp;", "", strtolower(strip_tags($fields['name']->content))));?>">
		<?php print $fields['name']->content; ?>
	</a>
</li>